# New ports collection makefile for:	GNU Ada gnat
# Date created:		Sat Mar 18 02:16:45 1995
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
PORTVERSION=	2006
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}:boot
MASTER_SITE_SUBDIR=	deischen/gcc/:boot
DISTFILES=	${GCC_SRCFILE}:gcc ${GNAT_SRCFILE}:gnat

MAINTAINER=	eischen@vigrid.com
COMMENT=	The GNU Ada Compiler system

CONFLICTS=	gcc-3.4.*
USE_GMAKE=	yes
USE_BISON=	yes
USE_PERL5_RUN=	yes

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/gcc-34
GNATNAME=	gnat-gpl-2006-src
GNUHOST=	${ARCH}-portbld-freebsd${OSREL}
GCC_VERSION=	3.4.6

# http://libre.adacore.com/:gcc
# http://libre.adacore.com/:gnat
GCC_SRCFILE=	gcc-3.4.6-src.tgz
GNAT_SRCFILE=	gnat-gpl-2006-src.tgz

PLIST_SUB=	GNUHOST=${GNUHOST} GCC_VERSION=${GCC_VERSION} \
		LIBRARY_VERSION=${LIBRARY_VERSION}

# Make no mistake about what host/target we are building on/for.
# This package does not support cross-compiling, and this fixes
# problems with bsd.port.mk files from earlier FreeBSD 3.x releases.
CONFIGURE_TARGET=	${GNUHOST}
CONFIGURE_ARGS=		--enable-languages="c,ada" \
			--program-prefix=gnat \
			--disable-nls \
			--with-system-zlib \
			--with-libiconv-prefix=${LOCALBASE}

TARGLIB=	${PREFIX}/lib/gcc/${GNUHOST}/${GCC_VERSION}
GNU_CONFIGURE=	yes
MAN1=		gnatgcc.1 gnatcpp.1 gnatgcov.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
NO_PACKAGE=	This version of GNAT produces GPL-tainted executables

# You need a compiler who calls an existing GNAT compiler (3.15 or greater).
# If you have one, point GNATGCC at it.  By default, we'll look for one in
# the path.  If we can't find one, we'll fetch a distfile containing
# a minimum (still pretty large) compiler toolset and use that to build.

GNATGCC!=	if ${WHICH} adagcc > /dev/null 2>&1; then \
			${ECHO_CMD} "`${WHICH} adagcc`"; \
		else \
			${ECHO_CMD} ""; \
		fi
GNATBIND!=	if ${WHICH} gnatbind > /dev/null 2>&1; then \
			${ECHO_CMD} "`${WHICH} gnatbind`"; \
		else \
			${ECHO_CMD} ""; \
		fi
.if empty(GNATGCC)
GNATGCC!=	if ${WHICH} gnatgcc > /dev/null 2>&1; then \
			${ECHO_CMD} "`${WHICH} gnatgcc`"; \
		else \
			${ECHO_CMD} ""; \
		fi
.endif

.if !empty(GNATGCC) && !empty(GNATBIND)
have_boot!=	if [ -x ${GNATGCC} -a -x ${GNATBIND} ]; then \
			${ECHO_CMD} "$$PATH"; \
		else \
			${ECHO_CMD} ""; \
		fi
.else
have_boot=
.endif

.if empty(have_boot)
ONLY_FOR_ARCHS=	i386
DISTFILES+=	gnat-3.15p-boot.tar.gz:boot
.if ${OSVERSION} >= 500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libc.so.4:${PORTSDIR}/misc/compat4x
.endif
# Warning!  You need the trailing slash on GCC_EXEC_PREFIX.
COMPILEDATA=	GCC_EXEC_PREFIX=${WRKDIR}/adaboot/lib/gcc-lib/ \
		ADA_INCLUDE_PATH=${WRKDIR}/adaboot/lib/gcc-lib/adainclude \
		ADA_OBJECTS_PATH=${WRKDIR}/adaboot/lib/gcc-lib/adalib
have_boot=	${WRKDIR}/adaboot/bin:${PATH}
GNATGCC=	adagcc
.endif

# Make sure we use the Ada-aware gcc compiler.
CC=		${GNATGCC}
CONFIGURE_ENV=	${COMPILE_DATA} PATH=${have_boot}

# Shared library handling
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		%%PREFIX%%/lib ${TARGLIB}
LIBRARY_VERSION=	2006
PLIST_SUB+=		SHAREDLIB=""
.else
CONFIGURE_ARGS+=	--disable-shared
PLIST_SUB+=		SHAREDLIB="@comment "
.endif

# Check for GNAT sources.
.if !exists(${DISTDIR}/${GNAT_SRCFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing and registration restrictions, you must fetch the\n\
source distribution manually.  Please access http://libre.adacore.com/\n\
with a web browser, register (it's free), and log in.  Download the source\n\
files:\n\
\t${GNAT_SRCFILE}\n\
\t${GCC_SRCFILE}\n\
and place them in ${DISTDIR}.\n
.endif

pre-patch:
	@${ECHO} "===>  Applying FreeBSD ports tree patches for gcc34."
	@( cd ${WRKSRC}; \
	    for i in ${PORTSDIR}/lang/gcc34/files/patch-*; do \
		${PATCH} ${PATCH_ARGS} < $$i; \
	    done )
	@${ECHO} "===>  Applying GNAT supplied patches for gcc34."
	@( cd ${WRKSRC}; \
	    ${PATCH} ${PATCH_ARGS} < ${WRKDIR}/${GNATNAME}/src/gcc-34.dif )
	@${ECHO} "===>  Moving GNAT compiler sources into GCC tree."
	@( ${MV} ${WRKDIR}/${GNATNAME}/src/ada ${WRKDIR}/gcc-34/gcc )

# Copy any additional files required into the correct locations, and also
# remove .orig files leftover from patching so they won't get installed.
post-patch:
	@(cd ${FILESDIR}; \
	    for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/gcc/ada; \
	    done )

pre-configure:
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/gcc/cstamp-h.in

#
# Can't get this to work with default bsd.port.mk do-configure target.
#
do-configure:
	@(cd ${WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

#
# We intentionally override CFLAGS because the build procedure is explicitly
# spelled out in gnat-3.13p-src/src/README.BUILD.  Remove CFLAGS from the
# do-build target at your own risk.
#
do-build:
	(cd ${WRKSRC}; \
	    PATH=${have_boot} \
	    ${SETENV} ${COMPILEDATA} ${GMAKE} CC=${CC} )
	(cd ${WRKSRC}; \
	    ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} PTHREAD_LIBS=${PTHREAD_LIBS} bootstrap )
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

do-install:
	(cd ${WRKSRC}; \
	    ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET} )
	${INSTALL_SCRIPT} ${WRKSRC}/gcc/ada/gnathtml.pl ${PREFIX}/bin

post-install:
	@(for prog in \
	    ${PREFIX}/bin/gnat \
	    ${PREFIX}/bin/gnatbind \
	    ${PREFIX}/bin/gnatbl \
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
	    ${PREFIX}/bin/${GNUHOST}-gcc-${GCC_VERSION} \
	    ${PREFIX}/bin/${GNUHOST}-gnatgcc \
	    ${PREFIX}/libexec/gcc/${GNUHOST}/${GCC_VERSION}/cc1 \
	    ${PREFIX}/libexec/gcc/${GNUHOST}/${GCC_VERSION}/gnat1 \
	    ${PREFIX}/libexec/gcc/${GNUHOST}/${GCC_VERSION}/collect2 ; \
	 do \
	    if [ -x $$prog ]; then \
		${STRIP_CMD} $$prog ; \
	    fi \
	done)
	@(chown -R root:wheel ${TARGLIB})
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libgcc_s.* ${TARGLIB}
.endif
	${RM} -f ${PREFIX}/lib/libiberty.a

.include <bsd.port.post.mk>
