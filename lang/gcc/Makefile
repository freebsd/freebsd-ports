# ex:ts=8 
# Ports collection makefile for:	egcs 
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

SNAPDATE=	2001-03-20
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	gcc-devel
PORTVERSION=	${SNAPVER}
CATEGORIES=	lang java
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/sourceware/gcc/snapshots/${SNAPDATE}/  \
		ftp://egcs.cygnus.com/pub/egcs/snapshots/${SNAPDATE}/  \
		ftp://ftp.ninemoons.com/pub/mirrors/egcs/snapshots/${SNAPDATE}/ \
		ftp://ftp.iij.ad.jp/pub/egcs/snapshots/${SNAPDATE}/ \
		ftp://ftp.yggdrasil.com/mirrors/site/egcs.cygnus.com/pub/egcs/snapshots/${SNAPDATE}/  \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/snapshots/
DISTFILES=	gcc-core-${SNAPVER}${EXTRACT_SUFX} \
		gcc-g++-${SNAPVER}${EXTRACT_SUFX} \
		gcc-g77-${SNAPVER}${EXTRACT_SUFX} \
		gcc-java-${SNAPVER}${EXTRACT_SUFX} \
		gcc-objc-${SNAPVER}${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org

NO_CDROM=	'dated material'

PATCH_ARGS=	-d ${SRCDIR} -E ${PATCH_STRIP}
.if !defined(PATCH_DEBUG)
PATCH_ARGS+=	--forward --quiet
.endif
CONFIGURE_SCRIPT=	../gcc-${SNAPVER}/configure

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

##WRKSRC=		${WRKDIR}/gcc-${SNAPVER}
##CONFIGURE_WRKSRC=	${WRKDIR}/build
##BUILD_WRKSRC=		${WRKDIR}/build
##INSTALL_WRKSRC=		${WRKDIR}/build
##CONFIGURE_SCRIPT=	${WRKSRC}/configure
EGCS_REV=	3.0
SRCDIR=		${WRKDIR}/gcc-${SNAPVER}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
PLIST_SUB=	EGCS_REV=${EGCS_REV} GNU_HOST=${CONFIGURE_TARGET}  \
		SNAPVER=${SNAPVER}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
CONFIGURE_ARGS=	--disable-nls --with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${TARGLIB}/include/g++
#CONFIGURE_ARGS+=	--program-prefix=e
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.else
CONFIGURE_ARGS+= --disable-shared
.endif
.if defined(WANT_THREADS_SUPPORT)
CONFIGURE_ARGS+= --enable-threads
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		gcpp.1 gg++.1 gg77.1 ggcc.1

pre-configure:
	@(MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	    ${PERL} -pi.orig -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" \
	    ${SRCDIR}/gcc/config/freebsd.h )
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	##@touch ${WRKSRC}/gcc/configure
	##@touch ${WRKSRC}/gcc/cstamp-h.in
	@touch ${SRCDIR}/gcc/configure
	@touch ${SRCDIR}/gcc/cstamp-h.in
	@${MKDIR} ${CONFIGURE_WRKSRC}
	#${RM} -rf ${SRCDIR}/libjava

pre-build:
	cd ${SRCDIR} ; contrib/gcc_update --touch

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1obj \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1plus \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cpp0 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/collect2 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/f771 ; \
	do \
		strip $$prog ; \
	done )
	${MV} -f ${PREFIX}/bin/gcc ${PREFIX}/bin/ggcc
	${MV} -f ${PREFIX}/bin/g++ ${PREFIX}/bin/gg++
	${MV} -f ${PREFIX}/bin/g77 ${PREFIX}/bin/gg77
	${MV} -f ${PREFIX}/bin/g++filt ${PREFIX}/bin/gg++filt
	${MV} -f ${PREFIX}/bin/gccbug ${PREFIX}/bin/gccbug-${SNAPVER}
	${RM} -f ${PREFIX}/bin/${GNU_HOST}-c++
	${RM} -f ${PREFIX}/bin/cpp
	# These 3 libraries are moved from PREFIX/lib to avoid conflicts
	# 	with the stock compiler.
	${MV} -f ${PREFIX}/lib/libiberty.a ${TARGLIB}
	${MV} -f ${PREFIX}/lib/libstdc++.* ${PREFIX}/lib/libsupc++.* ${TARGLIB}
	-${MV} -f ${PREFIX}/lib/ieee ${TARGLIB}
	${MV} -f ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/ggcc.1
	${MV} -f ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/gg++.1
	${MV} -f ${PREFIX}/man/man1/g77.1 ${PREFIX}/man/man1/gg77.1
	${MV} -f ${PREFIX}/man/man1/cpp.1 ${PREFIX}/man/man1/gcpp.1
#.if defined(WANT_SHAREDLIBS)
#	${MV} -f ${PREFIX}/lib/libstdc++.so* ${TARGLIB}
#.endif
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	cd ${PREFIX} ;\
	    find ${TARGLIB:S/^${PREFIX}\///} -type f -o -type l	\
	    	>${WRKDIR}/PLIST.gcc-lib
	cd ${PREFIX} ;\
	    find ${TARGLIB:S/^${PREFIX}\///} -type d \
	    	| sort -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.gcc-lib
	${ECHO} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO} "/Insert PLIST.gcc-lib"		>> ${WRKDIR}/ex.script
	${ECHO} "d"				>> ${WRKDIR}/ex.script
	${ECHO} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.post.mk>
