/*
 * Copyright (c) 2002-2003 Marius Strobl
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
 * $FreeBSD$
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
	size_t argc;
	const char **argv;
};

static void addarg(struct arglist *al, const char *arg);
int main(int argc, char *argv[], char *envp[]);

static void
addarg(struct arglist *al, const char *arg)
{
	const char **argv2;

	argv2 = realloc(al->argv, (al->argc + 1)* sizeof(al->argv[0]));

	if (argv2 == NULL)
		err(1, NULL);

	al->argv = argv2;

	al->argv[al->argc++] = arg;
}

int
main(int argc, char *argv[], char *envp[])
{
	size_t i;
	int bootstrap, cpp, dynamic, pic, gprof, stlinserted, threaded;
	const char *libc, *libc_r, *prefix;
	struct arglist al = { 0, NULL };

	if (argc == 1)
		errx(1, "no input files");

	if ((prefix = getenv("PREFIX")) == NULL)
		errx(1, "can't get PREFIX");

	bootstrap = cpp = dynamic = pic = gprof = stlinserted = threaded = 0;

#ifdef DEBUG
	printf("input: ");
#endif

#define	ARGCMP(x)	!strcmp(argv[i], (x))

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

	 	if (ARGCMP("-MT")) {
			threaded++;
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
		if (ARGCMP("-shared")) {
			dynamic++;
			continue;
		}

		/*
		 * Just link libstlport_icc* once when compiling the stlport
		 * tests.
		 */
		if (ARGCMP("-lstlport_icc")) {
			stlinserted++;
			continue;
		}

		/*
		 * Link against libc_p when "-qp" or "-p" were given,
		 * "/usr/lib/gcrt1.o" indicates this.
		 */
		if (ARGCMP("/usr/lib/gcrt1.o")) {
			gprof++;
			continue;
		}
	}

	/*
	 * Allow the user to specify an alternative threads library
	 * implementation, such as -lthr, or whatever
	 */
	if ((libc_r = getenv("PTHREAD_LIBS")) == NULL)
		libc_r = "-lc_r";
	/*
	 * Use the appropriate libs for libc and libc_r when linking static
	 * and "-KPIC" or "-pg" where given.
	 */
	if (!dynamic && (pic || gprof)) {
		/*
		 * Let libc_p win above libc_pic when both, "-KPIC" and "-pg",
		 * where given, GCC does the same.
		 */
		if (!gprof)
			libc = "-lc_pic";
		else {
			char	*p;
			libc = "-lc_p";
			asprintf(&p, "%s_p", libc_r);
			if (p == NULL)
				err(1, NULL);
			libc_r = p;
		}
	} else
		libc = "-lc";

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
		    ARGCMP("-MT") || ARGCMP("-PIC"))
			continue;

		/* prepend "-melf_i386" to the commandline */
		if (i == 0) {
			addarg(&al, argv[0]);
#if __FreeBSD_version < 500042
			addarg(&al, "-melf_i386");
#else
			addarg(&al, "-melf_i386_fbsd");
#endif
			continue;
		}

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
				addarg(&al, dynamic ? "-Bdynamic" : "-Bstatic");
				addarg(&al, "-lstlport_icc");
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
			    strncmp(al.argv[al.argc - 1], "-B", 2))
				addarg(&al, dynamic ? "-Bdynamic" : "-Bstatic");
			if (cpp || threaded) {
				addarg(&al, libc_r);
#if __FreeBSD_version >= 500016
				addarg(&al, dynamic ? "-Bdynamic" : "-Bstatic");
				addarg(&al, libc);
#endif
			} else
				addarg(&al, libc);
			continue;
		}

		/* Switch Linux stuff to FreeBSD counterparts. */
		if (ARGCMP("/lib/ld-linux.so.2")) {
#if __FreeBSD_version >= 501105
			addarg(&al, "/libexec/ld-elf.so.1");
#else
			addarg(&al, "/usr/libexec/ld-elf.so.1");
#endif
			continue;
		}
		if (ARGCMP("-L/usr/lib")) {
			char *temp;

			addarg(&al, "-L/usr/libexec/elf");
			addarg(&al, "-L/usr/libexec");
			addarg(&al, "-L/usr/lib");
			asprintf(&temp, "-L%s/lib", prefix);
			if (temp == NULL)
				err(1, NULL);
			addarg(&al, temp);
			continue;
		}

		/*
		 * Force libcxa and libunwind to static linkage, since the
		 * dynamic versions have glibc dependencies.
		 * Don't add superfluous -Bdynamic.
		 */
		if (ARGCMP("-Bdynamic") && i < argc - 1) {
			if (!strcmp(argv[i + 1], "-lcxa") ||
			    (cpp && !strcmp(argv[i + 1], "-lunwind"))) {
				addarg(&al, "-Bstatic");
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
		if (!strncmp(argv[i], "-l", 2) && al.argc > 0 &&
		    strncmp(al.argv[al.argc - 1], "-B", 2)) {
			if (!strcmp(argv[i], "-lcxa") ||
			    !strcmp(argv[i], "-limf") ||
			    !strcmp(argv[i], "-lirc") ||
			    !strcmp(argv[i], "-lircmt") ||
			    !strcmp(argv[i], "-lunwind"))
				addarg(&al, "-Bstatic");
			else
				addarg(&al, dynamic ? "-Bdynamic" : "-Bstatic");

			addarg(&al, argv[i]);
			continue;
	 	}

		/* default */
		addarg(&al, argv[i]);
	}

#undef	ARGCMP

	/* Still something to do ? */
	if (al.argc == 1)
		errx(1, "no input files");

#ifdef DEBUG
	printf("output: ");

	for (i = 0; i < al.argc; i++)
		printf("%s ", al.argv[i]);

	printf("\n");
#endif

	addarg(&al, NULL);

	/* Launch the real linker */
	if (execve(PATH_LD, (char **)al.argv, envp) == -1)
		err(1, "execing " PATH_LD);

	exit (1);
}
