# New ports collection makefile for:	GNU Ada gnat
# Date created:		Sat Mar 18 02:16:45 1995
# Whom:			hsu
# Porter (original):	nils@guru.ims.uni-stuttgart.de
# Porter (version 3):	maurice@serc.rmit.edu.au
#
# $FreeBSD$
#
# Note:
# - FreeBSD tasking libraries are included in the stock source.
# - The default names of a number of binaries have been altered to avoid
#   conflict with other gcc based products. Standard names can be provided
#   using symbolic links.

PORTNAME=		gnat
PORTVERSION=		2009
PORTREVISION=	4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_LOCAL}:boot
MASTER_SITE_SUBDIR=	deischen/gcc/:boot
DISTFILES=		${gcc_srcfile}:gcc ${gnat_srcfile}:gnat

MAINTAINER=		eischen@vigrid.com
COMMENT=		The GNU Ada Compiler system

LIB_DEPENDS=		gmp.10:${PORTSDIR}/math/gmp \
			mpfr.4:${PORTSDIR}/math/mpfr

ONLY_FOR_ARCHS=		i386

USE_GMAKE=		yes
USE_BISON=		build
USE_ICONV=		yes
USE_PERL5_BUILD=	yes

WRKSRC=			${WRKDIR}/build

MAN1=			gnatgcc.1 gnatcpp.1 gnatgcov.1
MAN7=			fsf-funding.7 gfdl.7 gpl.7
MAN7=			${fsf_mans:S/$/${fsf_suffix}.7/}

.include <bsd.port.pre.mk>

gcc_version=		4.3.4
fsf_mans=		fsf-funding gfdl gpl
fsf_suffix=		-${PORTNAME}
gnuhost=		${CONFIGURE_TARGET}
targlib=		${PREFIX}/lib/gcc-gnat
targlibexec=		${PREFIX}/libexec/gcc-gnat
gcc_srcdir=		gcc-43-src
gnat_srcdir=		gnat-gpl-2009-src
gcc_wrksrc=		${WRKDIR}/${gcc_srcdir}
gnat_wrksrc=		${WRKDIR}/${gnat_srcdir}
# http://libre.adacore.com/:gcc
# http://libre.adacore.com/:gnat
gcc_srcfile=		gcc-43-branch-20090519-src.tgz
gnat_srcfile=		gnat-gpl-2009-src.tgz

PATCH_WRKSRC=		${gcc_wrksrc}

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../${gcc_srcdir}/configure
CONFIGURE_ARGS=		--enable-languages="c,ada" \
			--program-prefix=gnat \
			--disable-nls \
			--with-system-zlib \
			--with-libiconv-prefix=${LOCALBASE} \
			--libdir=${targlib} \
			--libexecdir=${targlibexec} \
			--disable-libada
COMPILE_DATA=		MAKEINFO=${FALSE}
MAKE_ENV+=		PTHREAD_LIBS=${PTHREAD_LIBS}

PLIST_SUB=		GNUHOST=${gnuhost} GCC_VERSION=${gcc_version} \
			LIBRARY_VERSION=${LIBRARY_VERSION}

# You need a compiler who calls an existing GNAT compiler (3.15 or greater).
# If you have one, point GNATGCC at it.  By default, we'll look for one in
# the path.  If we can't find one, we'll fetch a distfile containing
# a minimum (still pretty large) compiler toolset and use that to build.

GNATGCC!=		if ${WHICH} gnatgcc > /dev/null 2>&1; then \
				${ECHO_CMD} "`${WHICH} gnatgcc`"; \
			else \
				${ECHO_CMD} ""; \
			fi
GNATBIND!=		if ${WHICH} gnatbind > /dev/null 2>&1; then \
				${ECHO_CMD} "`${WHICH} gnatbind`"; \
			else \
				${ECHO_CMD} ""; \
			fi

.if !empty(GNATGCC) && !empty(GNATBIND)
have_boot!=		if [ -x ${GNATGCC} -a -x ${GNATBIND} ]; then \
				${ECHO_CMD} "$$PATH"; \
			else \
				${ECHO_CMD} ""; \
			fi
.else
have_boot=
.endif

.if empty(have_boot)
DISTFILES+=		gnat-2005-boot.tgz:boot
BUILD_DEPENDS+=		${LOCALBASE}/lib/compat/libc.so.6:${PORTSDIR}/misc/compat6x
# Warning!  You need the trailing slash on GCC_EXEC_PREFIX.
COMPILE_DATA+=		GCC_EXEC_PREFIX=${WRKDIR}/adaboot/lib/gcc/ \
			ADA_INCLUDE_PATH=${WRKDIR}/adaboot/lib/gcc/adainclude \
			ADA_OBJECTS_PATH=${WRKDIR}/adaboot/lib/gcc/adalib
GNATGCC=		gnatgcc
have_boot=		${WRKDIR}/adaboot/bin:${WRKDIR}/adaboot/libexec/gcc:${PATH}
.endif

# Make sure we use the Ada-aware gcc compiler.
CC=			${GNATGCC}
CONFIGURE_ENV+=		${COMPILE_DATA} CC=${GNATGCC} PATH=${have_boot}
MAKE_ENV+=		${COMPILE_DATA} PATH=${have_boot}

# Shared library handling
WANT_SHAREDLIBS=yes
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+=	--enable-shared
USE_LDCONFIG=	${PREFIX}/lib ${targlib}
LIBRARY_VERSION=	2009
PLIST_SUB+=		SHAREDLIB=""
.else
CONFIGURE_ARGS+=	--disable-shared
PLIST_SUB+=		SHAREDLIB="@comment "
.endif

# Check for GNAT sources.
.if !exists(${DISTDIR}/${gnat_srcfile}) && !defined(PACKAGE_BUILDING)
IGNORE=	Because of licensing and registration restrictions, you must fetch the source distribution manually. Please access http://libre.adacore.com/ with a web browser, register (it's free), and log in.  Download the source files: ${gnat_srcfile} ${gcc_srcfile} and place them in ${DISTDIR}.
.endif

pre-patch:
	@${ECHO} "===>  Applying FreeBSD ports tree patches for gcc34."
	@${ECHO} "===>  Applying GNAT supplied patches for gcc43."
	@( cd ${gcc_wrksrc}/; \
	    ${CAT} ${gnat_wrksrc}/src/gcc-43.dif \
		| ${AWK} ' { sub("\r", ""); print $0 }' | ${PATCH} ${PATCH_ARGS} )
	@${ECHO} "===>  Moving GNAT compiler sources into GCC tree."
	@( ${MV} ${gnat_wrksrc}/src/ada ${gcc_wrksrc}/gcc )

pre-configure:
	@${MKDIR} ${WRKSRC}
	cd ${gcc_wrksrc} ; contrib/gcc_update --touch
	${RM} -f ${gcc_wrksrc}/gcc/*/*.info*
	@${TOUCH} ${TOUCH_FLAGS} ${gcc_wrksrc}/gcc/cstamp-h.in

do-build:
	(cd ${WRKSRC}; \
	    PATH=${have_boot} \
	    ${SETENV} ${COMPILE_DATA} ${GMAKE} CC=${CC} )
	(cd ${WRKSRC}; \
	    ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} PTHREAD_LIBS=${PTHREAD_LIBS} bootstrap-lean )
	(cd ${WRKSRC}; \
	    ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} -C gcc PTHREAD_LIBS=${PTHREAD_LIBS} gnatlib )
.if defined(WANT_SHAREDLIBS)
	(cd ${WRKSRC}; \
	    ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} -C gcc PTHREAD_LIBS=${PTHREAD_LIBS} gnatlib-shared )
.endif
	(cd ${WRKSRC}; \
	    ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} -C gcc PTHREAD_LIBS=${PTHREAD_LIBS} gnattools )

post-install:
	${INSTALL_SCRIPT} ${gcc_wrksrc}/gcc/ada/gnathtml.pl ${PREFIX}/bin
	@(for prog in \
	    ${PREFIX}/bin/gnat \
	    ${PREFIX}/bin/gnatbind \
	    ${PREFIX}/bin/gnatchop \
	    ${PREFIX}/bin/gnatclean \
	    ${PREFIX}/bin/gnatcpp \
	    ${PREFIX}/bin/gnatfind \
	    ${PREFIX}/bin/gnatgcc \
	    ${PREFIX}/bin/gnatgcov \
	    ${PREFIX}/bin/gnatkr \
	    ${PREFIX}/bin/gnatlink \
	    ${PREFIX}/bin/gnatls \
	    ${PREFIX}/bin/gnatmake \
	    ${PREFIX}/bin/gnatname \
	    ${PREFIX}/bin/gnatprep \
	    ${PREFIX}/bin/gnatxref \
	    ${PREFIX}/bin/${gnuhost}-gcc-${gcc_version} \
	    ${PREFIX}/bin/${gnuhost}-gnatgcc \
	    ${targlibexec}/${gnuhost}/${gcc_version}/cc1 \
	    ${targlibexec}/${gnuhost}/${gcc_version}/gnat1 \
	    ${targlibexec}/${gnuhost}/${gcc_version}/collect2 ; \
	 do \
	    if [ -x $$prog ]; then \
		${STRIP_CMD} $$prog ; \
	    fi \
	done)
	@(${CHOWN} -R root:wheel ${targlib})
	@(${CHOWN} -R root:wheel ${targlibexec})
	# This empty fortran directory is making trouble.
	${RM} -rf ${PREFIX}/lib/gcc-gnat/gcc/${CONFIGURE_TARGET}/${gcc_version}/finclude
	# Version FSF funding and licensing manuals. XXX Fix before it happens!
	for mp in ${fsf_mans}; do \
	    ${MV} -f ${PREFIX}/man/man7/$${mp}.7 \
	        ${PREFIX}/man/man7/$${mp}${fsf_suffix}.7; \
	done
	# Prepare a temporary list of installed libraries and include files.
	${RM} -f ${WRKDIR}/PLIST.lib
	for d in lib/gcc-gnat libexec/gcc-gnat/gcc/${CONFIGURE_TARGET}/; do \
	    cd ${PREFIX}; \
	    if [ -d $${d} ]; then \
	        ${FIND} $${d} -type f -o -type l >>${WRKDIR}/PLIST.lib; \
	        ${FIND} $${d} -type d | ${SORT} -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib; \
	    fi; \
	done
	# Following directories should be removed on deinstall if empty. Add them to the temporary list.
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc-gnat/gcc/${CONFIGURE_TARGET} 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc-gnat/gcc 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc-gnat 2>/dev/null || true" >> ${WRKDIR}/PLIST.lib
	# Insert the temporary list in the packing list.
	cd ${WRKDIR}; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
