# ex:ts=8 
# Ports collection makefile for:	egcs 
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

SNAPDATE=	2000-10-02
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
DISTFILES=	egcs-core-${SNAPVER}${EXTRACT_SUFX} \
		egcs-g++-${SNAPVER}${EXTRACT_SUFX} \
		egcs-g77-${SNAPVER}${EXTRACT_SUFX} \
		egcs-java-${SNAPVER}${EXTRACT_SUFX} \
		egcs-objc-${SNAPVER}${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org

NO_CDROM=	'dated material'

EGCS_REV=	2.97
LIBSTDCPP_REV=	4
SRCDIR=		${WRKDIR}/egcs-${SNAPVER}
WRKSRC=		${WRKDIR}/build
PATCH_ARGS=	-d ${SRCDIR} -E ${PATCH_STRIP}
.if !defined(PATCH_DEBUG)
PATCH_ARGS+=	--forward --quiet
.endif
CONFIGURE_SCRIPT=	../egcs-${SNAPVER}/configure

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

PLIST_SUB=	EGCS_REV=${EGCS_REV} GNU_HOST=${CONFIGURE_TARGET}  \
		LIBSTDCPP_REV=${LIBSTDCPP_REV} SNAPVER=${SNAPVER}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
CONFIGURE_ARGS=	--disable-nls --with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/include/g++
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.endif
.if defined(WANT_THREADS_SUPPORT)
CONFIGURE_ARGS+= --enable-threads
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		ecpp.1 eg++.1 eg77.1 egcc.1

pre-configure:
	@(MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	    ${PERL} -pi.orig -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" \
	    ${SRCDIR}/gcc/config/freebsd.h )
	@${CP} ${FILESDIR}/alpha-freebsd.h ${SRCDIR}/gcc/config/alpha/freebsd.h
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@touch ${SRCDIR}/gcc/configure
	@touch ${SRCDIR}/gcc/cstamp-h.in
	@${MKDIR} ${CONFIGURE_WRKSRC}

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
	${MV} ${PREFIX}/bin/gcc ${PREFIX}/bin/egcc
	${MV} ${PREFIX}/bin/g++ ${PREFIX}/bin/eg++
	${MV} ${PREFIX}/bin/g77 ${PREFIX}/bin/eg77
	${MV} ${PREFIX}/bin/g++filt ${PREFIX}/bin/eg++filt
	${MV} ${PREFIX}/bin/gccbug ${PREFIX}/bin/gccbug-${SNAPVER}
	${RM} -f ${PREFIX}/bin/${GNU_HOST}-c++
	${RM} -f ${PREFIX}/bin/cpp
	# These 3 libraries are moved from PREFIX/lib to avoid conflicts
	# 	with the stock compiler.
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a.${LIBSTDCPP_REV}  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
	cd ${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV} ; \
		${LN} -sf libstdc++.a.${LIBSTDCPP_REV} libstdc++.a
	${MV} -f ${PREFIX}/lib/libzgcj.*  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
	${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/egcc.1
	${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/eg++.1
	${MV} ${PREFIX}/man/man1/g77.1 ${PREFIX}/man/man1/eg77.1
	${MV} ${PREFIX}/man/man1/cpp.1 ${PREFIX}/man/man1/ecpp.1
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so*  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
.endif
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	cd ${PREFIX} ;\
	    find lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV} \
		-type f -o -type l >${WRKDIR}/PLIST.gcc-lib
	${ECHO} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO} "/Insert PLIST.gcc-lib"		>> ${WRKDIR}/ex.script
	${ECHO} "d"				>> ${WRKDIR}/ex.script
	${ECHO} "r ${WRKDIR}/PLIST.gcc-lib"	>> ${WRKDIR}/ex.script
	${ECHO} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-gcc-lib
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.post.mk>
