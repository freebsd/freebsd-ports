# ex:ts=8 
# Ports collection makefile for:	egcs 
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

SNAPDATE=	2000-05-01
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	gcc-devel
PORTVERSION=	${SNAPVER}
CATEGORIES=	lang java
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/egcs/snapshots/${SNAPDATE}/  \
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

.include <bsd.port.pre.mk>

EGCS_REV=	2.96
LIBSTDCPP_REV=	4
WRKSRC=		${WRKDIR}/egcs-${SNAPVER}

.if ${PORTOBJFORMAT} == "elf"
.if ${MACHINE_ARCH} == "i386"
PLIST=		${WRKDIR}/PLIST
.endif
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

PLIST_SUB=	EGCS_REV=${EGCS_REV} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/include/g++
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.endif
.if defined(WANT_THREADS)
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		eg++.1 eg77.1 egcc.1

pre-patch:
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd.h ${WRKSRC}/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd-elf.h ${WRKSRC}/gcc/config/i386/freebsd.h

pre-configure:
	@(MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${PERL} -pi.orig -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" \
		${WRKSRC}/gcc/config/freebsd.h )
	@${CP} ${FILESDIR}/alpha-freebsd.h ${WRKSRC}/gcc/config/alpha/freebsd.h
.if ${PORTOBJFORMAT} == "elf" && ${MACHINE_ARCH} == "i386"
	@${SED} -e 's/^@comment ELF-only://' ${PKGDIR}/PLIST >${PLIST}
.endif
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
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1obj \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cc1plus \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/cpp \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/collect2 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/f771 ; \
	do \
		strip $$prog ; \
	done)
	${MV} ${PREFIX}/bin/gcc ${PREFIX}/bin/egcc
	${MV} ${PREFIX}/bin/g++ ${PREFIX}/bin/eg++
	${MV} ${PREFIX}/bin/g77 ${PREFIX}/bin/eg77
	${MV} ${PREFIX}/bin/g++filt ${PREFIX}/bin/eg++filt
	${RM} -f ${PREFIX}/bin/cpp
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a.${LIBSTDCPP_REV}  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/libstdc++.a
	${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/egcc.1
	${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/eg++.1
	${MV} ${PREFIX}/man/man1/g77.1 ${PREFIX}/man/man1/eg77.1
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so*  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
.endif
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.post.mk>
