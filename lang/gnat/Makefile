
# New ports collection makefile for:	GNU Ada gnat
# Date created:         Sat Mar 18 02:16:45 1995
# Whom:			hsu
# Porter (original):	nils@guru.ims.uni-stuttgart.de
# Porter (version 3):	maurice@serc.rmit.edu.au
#
# $FreeBSD$
#
# Note:
# - FreeBSD tasking libraries created by Dan Eischen have been incorporated
#   into this edition
# - The default names of a number of binaries have been altered to avoid
#   conflict with other gcc based products. Standard names can be provided
#   using symbolic links.

PORTNAME=	gnat
PORTVERSION=	3.15p
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/${PORTVERSION}/:gnat \
		http://libre.act-europe.fr/GNAT/${PORTVERSION}/:gnat \
		${MASTER_SITE_LOCAL}:boot \
		ftp://ftp.gnu.org/pub/gnu/gcc/:gcc
MASTER_SITE_SUBDIR=	gcc/:gcc deischen/gcc/:boot
DISTFILES=	${GNATNAME}.tgz:gnat \
		gcc-2.8.1.tar.gz:gcc

MAINTAINER=	eischen@vigrid.com
COMMENT=	The GNU Ada Compiler system

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/gcc-2.8.1
GNATNAME=	gnat-${PORTVERSION}-src
GNUHOST=	${ARCH}-unknown-freebsd${OSREL}
GCC_VERSION=	2.8.1

PLIST_SUB=	GNUHOST=${GNUHOST} GCC_VERSION=${GCC_VERSION} \
		LIBRARY_VERSION=${LIBRARY_VERSION} \
		SHARED_MAJOR=${SHARED_MAJOR}
.if ${OSVERSION} < 600011
PLIST_FILES+=	lib/gcc-lib/${GNUHOST}/${GCC_VERSION}/include/math.h
.endif

# Make no mistake about what host/target we are building on/for.
# This package does not support cross-compiling, and this fixes
# problems with bsd.port.mk files from earlier FreeBSD 3.x releases.
CONFIGURE_TARGET=	--host=${GNUHOST} --target=${GNUHOST}
CONFIGURE_ARGS=		--program-prefix=ada
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		adagcc.1 cccp.1

# You need a compiler who calls an existing GNAT compiler (3.12 or greater).
# If you have one, point CC at it.  By default, we'll look for one in the
# obvious places.  If we can't find one, we'll fetch a distfile containing
# a minimum (still pretty large) compiler toolset and use that to build.

# For the GNAT compiler, we look in ${PREFIX} and in ${LOCALBASE}.
.ifdef PREFIX
have_boot!=	if [ -x ${PREFIX}/bin/adagcc -a -x ${PREFIX}/bin/gnatbind ]; then \
			${ECHO_CMD} "${PREFIX}/bin"; \
		else \
			${ECHO_CMD} ""; \
		fi
.else
have_boot=
.endif
.if empty(have_boot)
have_boot!=	if [ -x ${LOCALBASE}/bin/adagcc -a -x ${LOCALBASE}/bin/gnatbind ]; then \
			${ECHO_CMD} "${LOCALBASE}/bin"; \
		else \
			${ECHO_CMD} ""; \
		fi
.endif

#
# Check for attempts to cross-compile or build an aout GNAT compiler.
.if empty(have_boot)
have_boot!=	if [ ${PORTOBJFORMAT} = "aout" ]; then \
			${ECHO_CMD} "borken for aout"; \
		else \
			${ECHO_CMD} ""; \
		fi
.else
have_boot!=	if [ `file ${have_boot}/adagcc | awk ' { print $$2 }'` = "ELF" ]; then \
			if [ ${PORTOBJFORMAT} = "elf" ]; then \
				${ECHO_CMD} ${have_boot}; \
			else \
				${ECHO_CMD} "borken for aout"; \
			fi \
		else \
			${ECHO_CMD} "borken for aout"; \
		fi
.endif

.if ${have_boot} == "borken for aout"
BROKEN=	"Cannot build with or for an aout compiler."
.endif

.if empty(have_boot)
ONLY_FOR_ARCHS=	i386
DISTFILES+=	gnat-3.15p-boot.tar.gz:boot
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif
# Warning!  You need the trailing slash on GCC_EXEC_PREFIX.
COMPILEDATA=	GCC_EXEC_PREFIX=${WRKDIR}/adaboot/lib/gcc-lib/ \
		ADA_INCLUDE_PATH=${WRKDIR}/adaboot/lib/gcc-lib/adainclude \
		ADA_OBJECTS_PATH=${WRKDIR}/adaboot/lib/gcc-lib/adalib
have_boot=	${WRKDIR}/adaboot
.endif

# Make sure we use the Ada-aware gcc compiler.
CC =	adagcc
CONFIGURE_ENV=	${COMPILE_DATA} PATH=${have_boot}/bin:$$PATH

.if OVERRIDE_CFLAGS
GNATCFLAGS=	${CFLAGS}
GNATLIBCFLAGS=	${CFLAGS}
.else
GNATCFLAGS=	-O2
GNATLIBCFLAGS=	-O2
.endif

# Shared library handling
LIBRARY_VERSION=	3.15
SHARED_MAJOR=	1

# Account for signal set changes
.if ${OSVERSION} > 400010
SIGSET_WORDS=	4
SIGACTION=	new_struct_sigaction
.else
SIGSET_WORDS=	1
SIGACTION=	old_struct_sigaction
.endif

pre-patch:
	@if [ ! -f ${WRKSRC}/config/i386/freebsd-aout.h ]; then \
	 	${MV} ${WRKSRC}/config/i386/freebsd.h ${WRKSRC}/config/i386/freebsd-aout.h; \
		${MV} ${WRKSRC}/config/i386/freebsd-elf.h ${WRKSRC}/config/i386/freebsd.h; \
	fi
	@${ECHO} "===>  Applying FreeBSD patches to gcc for ${DISTNAME}"
	-( for i in ${PORTSDIR}/lang/gcc28/files/patch-*; do \
		${PATCH} ${PATCH_ARGS} < $$i; \
	    done )
	@${ECHO} "===>  Patching gcc for ${GNATNAME}"
	-( ${PATCH} ${PATCH_ARGS} < ${WRKDIR}/${GNATNAME}/src/gcc-281.dif )
	@${ECHO} "===>  Moving GNAT compiler sources into GCC tree."
	-( ${MV} ${WRKDIR}/${GNATNAME}/src/ada ${WRKDIR}/gcc-2.8.1 )
	@${ECHO} "===>  Making way for FreeBSD GNAT support files"
	-( ${RM} -f ${WRKSRC}/ada/[45]f* )

# Copy any additional files required into the correct locations, and also
# remove .orig files leftover from patching so they won't get installed.
post-patch:
	(cd ${FILESDIR}; \
	    for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/ada; \
	    done )
.if ${OSVERSION} >= 500016
	( ${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/freebsd5x-patch-01 )
.endif
	${RM} ${WRKDIR}/gnat-3.15p-src/examples/*.orig

pre-configure:
	@(cd ${WRKSRC}/config/${ARCH}/ ; \
	MAJ=`/sbin/sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${MV} freebsd.h freebsd.h.in ; \
	${SED} -e "s:__FreeBSD__=[0-9]*:__FreeBSD__=$${MAJ}:" freebsd.h.in \
		>freebsd.h)
	@(cd ${WRKSRC}/ada/ ; \
	${MV} 5fosinte.ads 5fosinte.ads.in ; \
	${SED} -e "s:__FreeBSD__sigset_words:${SIGSET_WORDS}:" \
		-e "s:__FreeBSD__sigaction:${SIGACTION}:" 5fosinte.ads.in \
		> 5fosinte.ads)
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/cstamp-h.in
	@(cd ${WRKSRC}/ada; \
	   ${TOUCH} treeprs.ads a-[es]info.h nmake.ad[bs])

#
# Can't get this to work with default bsd.port.mk do-configure target.
#
do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

#
# We intentionally override CFLAGS because the build procedure is explicitly
# spelled out in gnat-3.13p-src/src/README.BUILD.  Remove CFLAGS from the
# do-build target at your own risk.
#
do-build:
	(cd ${WRKSRC}; \
	    PATH=${have_boot}/bin:$$PATH \
	    ${COMPILEDATA} ${GMAKE} CC="${CC}" OLDCC="adagcc" CFLAGS="${GNATCFLAGS}" LANGUAGES="c ada gcov" )
	(cd ${WRKSRC}; \
	    ${GMAKE} CFLAGS="${GNATCFLAGS}" LANGUAGES="c ada gcov" bootstrap )
	(cd ${WRKSRC}; \
	    ${GMAKE} CFLAGS="${GNATCFLAGS}" GNATLIBCFLAGS="-fPIC ${GNATLIBCFLAGS}" \
	    soext=.so.${SHARED_MAJOR} LIBRARY_VERSION=${LIBRARY_VERSION} \
	    gnatlib-shared )
	${MV} ${WRKSRC}/ada/rts/lib*-${LIBRARY_VERSION}.so.${SHARED_MAJOR} \
		${WRKSRC}/ada
	${RM} ${WRKSRC}/stamp-gnatlib2
	(cd ${WRKSRC}; \
	    ${GMAKE} CFLAGS="${GNATCFLAGS}" GNATLIBCFLAGS="${GNATLIBCFLAGS}" gnatlib )
	(cd ${WRKSRC}; \
	    ${GMAKE} CFLAGS="${GNATCFLAGS}" gnattools )

do-install:
	(cd ${WRKSRC}; \
	    ${GMAKE} CC="${CC}" LANGUAGES="c ada gcov" ${INSTALL_TARGET} )
	${INSTALL_DATA} \
	    ${WRKSRC}/ada/libgnat-${LIBRARY_VERSION}.so.${SHARED_MAJOR} \
	    ${PREFIX}/lib
	${INSTALL_DATA} \
	    ${WRKSRC}/ada/libgnarl-${LIBRARY_VERSION}.so.${SHARED_MAJOR} \
	    ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/libgnat-${LIBRARY_VERSION}.so.${SHARED_MAJOR} \
	    ${PREFIX}/lib/gcc-lib/${GNUHOST}/${GCC_VERSION}/adalib/libgnat.so
	${LN} -s ${PREFIX}/lib/libgnarl-${LIBRARY_VERSION}.so.${SHARED_MAJOR} \
	    ${PREFIX}/lib/gcc-lib/${GNUHOST}/${GCC_VERSION}/adalib/libgnarl.so
	${INSTALL_SCRIPT} ${WRKSRC}/ada/gnathtml.pl ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} \
	    ${WRKDIR}/gnat-3.15p-src/examples/* ${EXAMPLESDIR}
.endif

post-install:
	@(for prog in ${PREFIX}/bin/adagcc \
	    ${PREFIX}/bin/adagcov \
	    ${PREFIX}/bin/gnat \
	    ${PREFIX}/bin/gnatbind \
	    ${PREFIX}/bin/gnatbl \
	    ${PREFIX}/bin/gnatchop \
	    ${PREFIX}/bin/gnatfind \
	    ${PREFIX}/bin/gnatkr \
	    ${PREFIX}/bin/gnatlink \
	    ${PREFIX}/bin/gnatls \
	    ${PREFIX}/bin/gnatmake \
	    ${PREFIX}/bin/gnatmem \
	    ${PREFIX}/bin/gnatprep \
	    ${PREFIX}/bin/gnatpsta \
	    ${PREFIX}/bin/gnatpsys \
	    ${PREFIX}/bin/gnatxref \
	    ${PREFIX}/bin/${GNUHOST}-gcc \
	    ${PREFIX}/lib/gcc-lib/${GNUHOST}/${GCC_VERSION}/cc1 \
	    ${PREFIX}/lib/gcc-lib/${GNUHOST}/${GCC_VERSION}/gnat1 \
	    ${PREFIX}/lib/gcc-lib/${GNUHOST}/${GCC_VERSION}/cpp ; do \
	    if [ -x $$prog ]; then \
		${STRIP_CMD} $$prog ; \
	    fi \
	done)
	@(${TOUCH} ${TOUCH_FLAGS} ${PREFIX}/lib/gcc-lib/${GNUHOST}/${GCC_VERSION}/include/float.h)
	@(chown -R bin:bin ${PREFIX}/lib/gcc-lib/${GNUHOST}/${GCC_VERSION})
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
