/*
 * Copyright (c) 2002 Marius Strobl
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Wrapper for Intel(R) C/C++ Compiler for Linux to allow linking of native
 * FreeBSD binaries.
 * Based on a shell-script written by Dan Nelson <dnelson@allantgroup.com>
 * with some modifications by Alexander Leidinger <netchild@FreeBSD.org>.
 *
 * $FreeBSD: /tmp/pcvs/ports/lang/ifc/files/ld.c,v 1.1 2002-11-18 09:27:32 maho Exp $
 */

/* Uses code marked: */

/*	OpenBSD: mailwrapper.c,v 1.6 1999/12/17 05:06:28 mickey Exp	*/
/*	NetBSD: mailwrapper.c,v 1.3 1999/05/29 18:18:15 christos Exp	*/
/* FreeBSD: src/usr.sbin/mailwrapper/mailwrapper.c,v 1.8 2002/07/11 18:27:55 alfred Exp */

/*
 * Copyright (c) 1998
 * 	Perry E. Metzger.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgment:
 *	This product includes software developed for the NetBSD Project
 *	by Perry E. Metzger.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#if defined (__FreeBSD__) && __FreeBSD__ >= 2
	#include <osreldate.h>
#else
	#error "Won't work here."
#endif

#define	PATH_LD	"/usr/bin/ld"

struct arglist {
	size_t argc, maxc;
	char **argv;
};

static void initarg(struct arglist *al);
static void addarg(struct arglist *al, const char *arg, int copy);
static void freearg(struct arglist *al, int copy);
int main(int argc, char *argv[], char *envp[]);

static void
initarg(struct arglist *al)
{

	al->argc = 0;
	al->maxc = 10;
	if ((al->argv = malloc(al->maxc * sizeof(char *))) == NULL)
		err(1, NULL);
}

static void
addarg(struct arglist *al, const char *arg, int copy)
{
	char **argv2;

	if (al->argc == al->maxc) {
		al->maxc <<= 1;

		if ((argv2 = realloc(al->argv,
		    al->maxc * sizeof(char *))) == NULL) {
			if (al->argv)
				free(al->argv);
			al->argv = NULL;
			err(1, NULL);
		} else {
			al->argv = argv2;
		}
	}
	if (copy) {
		if ((al->argv[al->argc++] = strdup(arg)) == NULL)
			err(1, NULL);
	} else {
		al->argv[al->argc++] = (char *)arg;
	}
}

static
void freearg(struct arglist *al, int copy)
{
	size_t i;

	if (copy)
		for (i = 0; i < al->argc; i++)
			free(al->argv[i]);
	free(al->argv);
}

int
main(int argc, char *argv[], char *envp[])
{
	size_t i;
	int bootstrap, cpp, dynamic, pic, gprof, stlinserted, threaded;
	char *libc, *libc_r, *prefix;
	struct arglist al;

	if (argc == 1)
		errx(1, "no input files");

	if ((prefix = getenv("PREFIX")) == NULL)
		errx(1, "can't get PREFIX");

	initarg(&al);
	bootstrap = cpp = dynamic = pic = gprof = stlinserted = threaded = 0;

#ifdef DEBUG
	printf("input: ");
#endif

#define	ARGCMP(x)	!strcmp(argv[i], (x))
#define	ARGCMPB(x, y)	(strlen(x) + strlen(y) == strlen(argv[i]) &&	       \
	!strncmp(argv[i], (x), strlen(x)) &&				       \
	!strncmp(argv[i] + strlen(x), (y), strlen(y)))

	/*
	 * XXX This doesn't deal with whitespace but a) the output of the
	 *     compiler should be fixed and b) the real linker is also picky
	 *     about whitespace.
	 */
	for (i = 0; i < argc; i++) {
#ifdef DEBUG
		printf("%s ", argv[i]);
#endif

	 	if (ARGCMP("-CPLUSPLUS")) {
			cpp++;
			continue;
	    	}

		if (ARGCMP("-BOOTSTRAPSTLPORT")) {
			bootstrap++;
			continue;
		}

	 	if (ARGCMP("-PIC")) {
			pic++;
			continue;
	    	}

		/*
		 * If the compiler was called with -static we shouldn't see
		 * "--dynamic-linker" here.
		 * Note: According to ld(1) this is "--dynamic-linker" but
		 *	 ICC passes "-dynamic-linker" to it.
		 */
		if (ARGCMP("--dynamic-linker") || ARGCMP("-dynamic-linker")) {
			dynamic++;
			continue;
		}

		/*
		 * Just link libstlport_icc* once when compiling the stlport
		 * tests.
		 */
		if (!strncmp(argv[i], "-lstlport_icc",
		    strlen("-lstlport_icc"))) {
			stlinserted++;
			continue;
		}

		/*
		 * If IFC, do not use libstlport_icc.
		 */
		if (!strcmp(argv[i], "-lF90")) {
			stlinserted++;
			continue;
		}

		/*
		 * ICC links the thread safe libircmt instead of libirc when
		 * told to generate threaded code by any of the compiler flags
		 * "-mt", "-openmp" or "-parallel". We use this as an indicator
		 * to link against libc_r.
		 */
		if (ARGCMP("-lircmt")) {
			threaded++;
			continue;
		}

		/*
		 * Link against libc_p when "-pg" was given, "/usr/lib/gcrt1.o"
		 * indicates this.
		 */
		if (ARGCMP("/usr/lib/gcrt1.o")) {
			gprof++;
			continue;
		}
	}

	/*
	 * Use the appropriate libs for libc and libc_r when linking static
	 * and "-KPIC" or "-pg" where given.
	 */
	if (!dynamic && (pic || gprof)) {
		/*
		 * Let libc_p win above libc_pic when both, "-KPIC" and "-pg",
		 * where given, GCC does the same.
		 */
		if (!gprof) {
			libc = strdup("-lc_pic");
			libc_r = strdup("-lc_r");
		} else {
			libc = strdup("-lc_p");
			libc_r = strdup("-lc_r_p");
		}
	} else {
		libc = strdup("-lc");
		libc_r = strdup("-lc_r");
	}

#ifdef DEBUG
	printf("\ncpp: %s bootstrap: %s dynamic: %s gprof: %s pic: %s "
	    "threaded: %s\n", cpp ? "YES" : "NO", bootstrap ? "YES" : "NO",
	    dynamic ? "YES" : "NO", gprof ? "YES" : "NO", pic ? "YES" : "NO",
	    threaded ? "YES" : "NO");
#endif

	if (bootstrap && !cpp)
		errx(1, "-BOOTSTRAPSTLPORT is only valid in combination with "
		    "-CPLUSPLUS");

	for (i = 0; i < argc; i++) {
	 	if (ARGCMP("-CPLUSPLUS") || ARGCMP("-BOOTSTRAPSTLPORT") ||
		    ARGCMP("-PIC"))
			continue;

		/* prepend "-melf_i386" to the commandline */
		if (i == 0) {
			addarg(&al, argv[0], 1);
#if __FreeBSD_version < 500042
			addarg(&al, "-melf_i386", 1);
#else
			addarg(&al, "-melf_i386_fbsd", 1);
#endif
			continue;
		}

		/*
		 * "-u ___pseudo_link" triggers linking of additional objects
		 * from libcxa which seem to bloat the binaries, i.e. they
		 * perfectly work without it. Intel Support promised to look
		 * up what this servers for...
		 */
	 	if (ARGCMP("-u") || ARGCMP("___pseudo_link"))
			continue;

		/* Don't add obsolete flag "-Qy". */
		if (ARGCMP("-Qy"))
			continue;

		/* Libunwind is only needed when compiling C++ source. */
		if (!cpp && ARGCMP("-lunwind"))
			continue;

		/*
		 * Replace libcprts with libstlport_icc. The Dinkumware STL
		 * shipping with ICC has unresolvable glibc dependencies
		 * in both, the static and the dynamic, versions.
		 */
		if (ARGCMP("-lcprts")) {
			if (cpp && !bootstrap && !stlinserted) {
				addarg(&al,
				    dynamic ? "-Bdynamic" : "-Bstatic", 1);
				addarg(&al, "-lstlport_icc", 1);
				stlinserted++;
			}
			continue;
		}

		/*
		 * Link against libc_r when compiling multi-threaded or C++
		 * code (libcxa and libunwind depend on libc_r when compiling
		 * C++ source).
		 */
		if (ARGCMP("-lc")) {
			if (al.argc > 0 &&
			    strncmp(al.argv[al.argc - 1], "-B", strlen("-B")))
				addarg(&al,
				    dynamic ? "-Bdynamic" : "-Bstatic", 1);
			if (cpp || threaded) {
#if __FreeBSD_version < 500016
				addarg(&al, libc_r, 0);
#else
				addarg(&al, libc, 0);
				addarg(&al,
				    dynamic ? "-Bdynamic" : "-Bstatic", 1);
				addarg(&al, libc_r, 0);
#endif
			} else {
				addarg(&al, libc, 0);
			}
			continue;
		}

		/* Switch Linux stuff to FreeBSD counterparts. */
		if (ARGCMP("/lib/ld-linux.so.2")) {
			addarg(&al, "/usr/libexec/ld-elf.so.1", 1);
			continue;
		}
		if (ARGCMP("-L/usr/lib")) {
			char *temp;

			if ((temp = (char *) malloc(strlen("-L") +
			    strlen(prefix) + strlen("/lib") + 1)) == NULL)
				err(1, NULL);

			addarg(&al, "-L/usr/libexec/elf", 1);
			addarg(&al, "-L/usr/libexec", 1);
			addarg(&al, "-L/usr/lib", 1);
			snprintf(temp, strlen("-L") + strlen(prefix) +
			    strlen("/lib") + 1, "-L%s/lib", prefix);
			addarg(&al, temp, 1);
			free(temp);
			continue;
		}

		/*
		 * Link and map files for C++ exception handling.
		 */
		if (!cpp &&
		    (ARGCMP("--version-script") ||
		    ARGCMPB(prefix, "/intel/compiler60/ia32/lib/icrt.link") ||
		    ARGCMPB(prefix,
			"/intel/compiler60/ia32/lib/icrt.internal.map")))
			continue;

		/*
		 * Force libcxa and libunwind to static linkage, since the
		 * dynamic versions have glibc dependencies.
		 * Don't add superfluous -Bdynamic.
		 */
		if (ARGCMP("-Bdynamic") && i < argc - 1) {
			if (!strcmp(argv[i + 1], "-lcxa") ||
			    (cpp && !strcmp(argv[i + 1], "-lunwind"))) {
				addarg(&al, "-Bstatic", 1);
				continue;
			}

			if (!strcmp(argv[i + 1], "-lcprts") ||
			    !strcmp(argv[i + 1], "-lunwind"))
				continue;
		}

		/* Don't add superfluous -Bstatic. */
		if (ARGCMP("-Bstatic") && i < argc - 1 &&
		    (!strcmp(argv[i + 1], "-lcprts") ||
		    (!cpp && !strcmp(argv[i + 1], "-lunwind"))))
			continue;

		/*
		 * Sanity check if every lib is prepended by a linkage option,
		 * add if missing.
		 */
		if (!strncmp(argv[i], "-l", strlen("-l")) && al.argc > 0 &&
		    strncmp(al.argv[al.argc - 1], "-B", strlen("-B"))) {
			if (!strcmp(argv[i], "-lcxa") ||
			    !strcmp(argv[i], "-limf") ||
			    !strcmp(argv[i], "-lirc") ||
			    !strcmp(argv[i], "-lircmt") ||
			    !strcmp(argv[i], "-lunwind"))
				addarg(&al, "-Bstatic", 1);
			else
				addarg(&al,
				    dynamic ? "-Bdynamic" : "-Bstatic", 1);

			addarg(&al, argv[i], 1);
			continue;
	 	}

		/* default */
		addarg(&al, argv[i], 1);
	}

#undef	ARGCMP
#undef	ARGCMPB

	/* Still something to do ? */
	if (al.argc == 1)
		errx(1, "no input files");

#ifdef DEBUG
	printf("output: ");

	for (i = 0; i < al.argc; i++)
		printf("%s ", al.argv[i]);

	printf("\n");
#endif

	addarg(&al, NULL, 0);

	/* Launch the real linker */
	if (execve(PATH_LD, al.argv, envp) == -1)
		err(1, "execing %s", PATH_LD);

	freearg(&al, 1);

	exit (1);
}
