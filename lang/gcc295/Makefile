# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.3.test1
CATEGORIES=	lang java
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/sourceware/gcc/releases/gcc-2.95.3-prerelease/  \
		ftp://ftp.freesoftware.com/pub/sourceware/gcc/releases/${DISTNAME}/  \
		ftp://egcs.cygnus.com/pub/egcs/releases/${DISTNAME}/  \
		ftp://ftp.ninemoons.com/pub/mirrors/egcs/releases/${DISTNAME}/ \
		ftp://ftp.iij.ad.jp/pub/egcs/releases/${DISTNAME}/  \
		ftp://ftp.yggdrasil.com/mirrors/site/egcs.cygnus.com/pub/egcs/releases/${DISTNAME}/  \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/releases/${DISTNAME}/
MASTER_SITE_SUBDIR=	gcc
DISTFILES=	gcc-core-${GCC_REV}.test1${EXTRACT_SUFX} \
		gcc-g++-${GCC_REV}.test1${EXTRACT_SUFX} \
		gcc-g77-${GCC_REV}.test1${EXTRACT_SUFX} \
		gcc-java-${GCC_REV}.test1${EXTRACT_SUFX} \
		gcc-objc-${GCC_REV}.test1${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org

#USE_BZIP2=	yes

.include <bsd.port.pre.mk>

GCC_REV=	${DISTNAME:S/gcc-//g:S/.test1//g}
LIBSTDCPP_REV=	2100

.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

PLIST_SUB+=	EGCS_REV=${GCC_REV} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/include/g++
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.endif
.if defined(WANT_THREADS)
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		cccp.1 g++295.1 g77.1 gcc295.1

pre-patch:
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd.h ${WRKSRC}/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd-elf.h ${WRKSRC}/gcc/config/i386/freebsd.h

pre-configure:
	@(MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${SED} -e "s:__FreeBSD__[0-9=]*:__FreeBSD__=$${MAJ}:" ${FILESDIR}/freebsd.h \
		>${WRKSRC}/gcc/config/freebsd.h )
	@${CP} ${FILESDIR}/alpha-freebsd.h ${WRKSRC}/gcc/config/alpha/freebsd.h
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@touch ${WRKSRC}/gcc/configure
	@touch ${WRKSRC}/gcc/cstamp-h.in

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
		${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1obj \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1plus \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cpp0 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/collect2 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/f771 ; \
	do \
		strip $$prog ; \
	done)
	${MV} ${PREFIX}/bin/gcc ${PREFIX}/bin/gcc295
	${MV} ${PREFIX}/bin/g++ ${PREFIX}/bin/g++295
	${MV} ${PREFIX}/bin/g77 ${PREFIX}/bin/g77
	${MV} ${PREFIX}/bin/g++filt ${PREFIX}/bin/g++filt295
	${RM} -f ${PREFIX}/bin/cpp
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a.${LIBSTDCPP_REV}  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/libstdc++.a
	${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/gcc295.1
	${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/g++295.1
	${MV} ${PREFIX}/man/man1/g77.1 ${PREFIX}/man/man1/g77.1
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so*  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
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
