# New ports collection makefile for:	GNU Ada gnat
# Version required:     3.09
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

DISTNAME=       gcc-2.8.1
PKGNAME=        gnat-3.11p
CATEGORIES=	lang
MASTER_SITES=   ftp://cs.nyu.edu/pub/gnat/ \
		${MASTER_SITE_GNU}
DISTFILES=      gnat-3.11p-src.tar.gz gcc-2.8.1.tar.gz

MAINTAINER=	eischen@vigrid.com

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
GNUHOST=	${ARCH}-unknown-freebsdelf${OSREL}
.else
GNUHOST=	${ARCH}-unknown-freebsd${OSREL}
.endif
GCC_VERSION=	2.8.1

PLIST_SUB=	GNUHOST=${GNUHOST} GCC_VERSION=${GCC_VERSION}
# Make no mistake about what host/target we are building on/for.
# This package does not support cross-compiling, and this fixes
# problems with bsd.port.mk files from earlier FreeBSD 3.x releases.
CONFIGURE_TARGET=	--host=${GNUHOST} --target=${GNUHOST}
CONFIGURE_ARGS=		--program-prefix=ada
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		adagcc.1 cccp.1

# You need a compiler who calls an existing GNAT compiler (3.10 or greater).
# If you have one, point CC at it.  By default, we'll look for one in the
# obvious places.  If we can't find one, we'll fetch a distfile containing
# a minimum (still pretty large) compiler toolset and use that to build.

# For the GNAT compiler, we look in ${PREFIX} and in /usr/local.
.ifdef PREFIX
have_boot!=	if [ -x ${PREFIX}/bin/adagcc -a -x ${PREFIX}/bin/gnatbind ]; then \
			${ECHO} "${PREFIX}/bin"; \
		else \
			${ECHO} ""; \
		fi
.else
have_boot=
.endif
.if empty(have_boot)
have_boot!=	if [ -x /usr/local/bin/adagcc -a -x /usr/local/bin/gnatbind ]; then \
			${ECHO} "/usr/local/bin"; \
		else \
			${ECHO} ""; \
		fi
.endif

#
# Check for attempts to cross-compile the GNAT compiler.  We only supply
# an ELF bootstrap compiler.  If the gnat-3.10 package is still around,
# you could possible install that and build gnat-3.11p as aout.  This
# is not supported, though.
.if empty(have_boot)
have_boot!=	if [ ${PORTOBJFORMAT} = "aout" ]; then \
			${ECHO} "borken for cross"; \
		else \
			${ECHO} ""; \
		fi
.else
have_boot!=	if [ `file ${have_boot}/adagcc | awk ' { print $$2 }'` = "ELF" ]; then \
			if [ ${PORTOBJFORMAT} = "elf" ]; then \
				${ECHO} ${have_boot}; \
			else \
				${ECHO} "borken for cross"; \
			fi \
		else \
			if [ ${PORTOBJFORMAT} = "elf" ]; then \
				${ECHO} ""; \
			else \
				${ECHO} ${have_boot}; \
			fi \
		fi
.endif

.if ${have_boot} == "borken for cross"
BROKEN=	"Cannot build an aout compiler with an ELF compiler."
.endif

.if empty(have_boot)
DISTFILES+=	gnat-3.11p-boot.tar.gz
# Warning!  You need the trailing slash on GCC_EXEC_PREFIX.
COMPILEDATA=	GCC_EXEC_PREFIX=${WRKDIR}/adaboot/lib/gcc-lib/ \
		ADA_INCLUDE_PATH=${WRKDIR}/adaboot/lib/gcc-lib/adainclude \
		ADA_OBJECTS_PATH=${WRKDIR}/adaboot/lib/gcc-lib/adalib
have_boot=	${WRKDIR}/adaboot
.endif

# Make sure we use the Ada-aware gcc compiler.
CC = adagcc
CONFIGURE_ENV=	${COMPILE_DATA} PATH=${have_boot}/bin:$$PATH

pre-patch:
	@${ECHO} "===>  Applying FreeBSD patches to gcc for ${DISTNAME}"
	-( ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/freebsdgcc28-patches )
	@${ECHO} "===>  Patching gcc for ${DISTNAME}"
	-( ${PATCH} ${PATCH_ARGS} < ${WRKDIR}/gnat-3.11p-src/src/gcc-281.dif )
	@${ECHO} "===>  Copying GNAT compiler sources into GCC tree."
	-( ${MV} ${WRKDIR}/gnat-3.11p-src/src/ada ${WRKDIR}/gcc-2.8.1 )

# Copy any additional files required into the correct locations.
post-patch:
	(cd ${FILESDIR}; \
	    for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/ada; \
	    done )

pre-configure:
	@(cd ${WRKDIR}/gcc-2.8.1/config/${ARCH}/ ; \
	MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${MV} freebsd.h freebsd.h.in ; \
	${SED} -e "s:__FreeBSD__=[0-9]*:__FreeBSD__=$${MAJ}:" freebsd.h.in \
		>freebsd.h ; \
	${MV} freebsd-elf.h freebsd-elf.h.in ; \
	${SED} -e "s:__FreeBSD__=[0-9]*:__FreeBSD__=$${MAJ}:" freebsd-elf.h.in \
		>freebsd-elf.h)
	@(cd ${WRKSRC}/ada; \
	   ${TOUCH} treeprs.ads a-[es]info.h nmake.ad[bs])

#
# Can't get this to work with default bsd.port.mk do-configure target.
#
do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

#
# We intentionally override CFLAGS because the build procedure is explicitly
# spelled out in gnat-3.11p-src/src/README.BUILD.  Remove CFLAGS from the
# do-build target at your own risk.
#
do-build:
	(cd ${WRKSRC}; \
	    PATH=${have_boot}/bin:$$PATH \
	    ${COMPILEDATA} ${GMAKE} CC="${CC}" OLDCC="adagcc" CFLAGS="-O2" LANGUAGES="c ada" )
	(cd ${WRKSRC}; \
	    ${GMAKE} CFLAGS="-O2" LANGUAGES="c ada" bootstrap )
	(cd ${WRKSRC}; \
	    ${GMAKE} CFLAGS="-O2" gnattools )
	(cd ${WRKSRC}; \
	    ${GMAKE} CFLAGS="-O2" GNATLIBCFLAGS="-O2" gnatlib )

do-install:
	(cd ${WRKSRC}; \
	    ${GMAKE} CC="${CC}" LANGUAGES="c ada" ${INSTALL_TARGET} )

post-install:
	@(for prog in ${PREFIX}/bin/adagcc \
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
		strip $$prog ; \
	    fi \
	done)
	@(${CHOWN} -R bin:bin ${PREFIX}/lib/gcc-lib/${GNUHOST}/${GCC_VERSION})
	@(${ECHO} "-----------------------------------------------------------" )
	@(${ECHO} "" )
	@(${ECHO} "For information about using the tasking library please read" )
	@(${ECHO} "the README.Tasking file" )
	@(${ECHO} "" )
	@(${ECHO} "-----------------------------------------------------------" )
	@(${ECHO} "" )

.include <bsd.port.post.mk>
