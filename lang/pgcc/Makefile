# ex:ts=8
# Ports collection makefile for:	pgcc
# Version required: 			1.1.1
# Date created:				10 Dec 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

DISTNAME=	egcs-1.1.2
PKGNAME=	pgcc-1.1.3
CATEGORIES=	lang
MASTER_SITES=	ftp://go.cygnus.com/pub/ftp.cygnus.com/egcs/releases/egcs-1.1.2/ \
		ftp://ftp.crc.ca/pub/packages/egcs/egcs-1.1.2/ \
		ftp://ftp.funet.fi/mirrors/ftp.cygnus.com/pub/egcs/releases/egcs-1.1.2/ \
		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.2/ \
		ftp://ftp.nluug.nl/pub/languages/egcs/releases/egcs-1.1.2/ \
		ftp://ftp.iij.ad.jp/pub/egcs/releases/egcs-1.1.2/ \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/releases/egcs-1.1.2/ \
		ftp://cambridge.cygnus.com/pub/egcs/releases/egcs-1.1.2/
DISTFILES=	egcs-core-1.1.2${EXTRACT_SUFX} egcs-g++-1.1.2${EXTRACT_SUFX} \
		egcs-g77-1.1.2${EXTRACT_SUFX} egcs-objc-1.1.2${EXTRACT_SUFX}

PATCH_SITES=	http://www.gcc.ml.org/data/source/  \
		ftp://ftp.goof.com/pub/pcg/source/  \
		ftp://ftp.hitachi-sk.co.jp/pub/pentium-gcc/source/  \
		ftp://ftp.fu-berlin.de/unix/languages/pgcc/source/
PATCHFILES=	egcs-1.1.2-pgcc-1.1.3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=  autoconf:${PORTSDIR}/devel/autoconf

BROKEN='waiting for new patches against gcc-2.95.1'

.include <bsd.port.pre.mk>

USE_BZIP2=	yes

EGCS_REV=	pgcc-2.91.66
LIBSTDCPP_REV=	2.9.0

.if ${PORTOBJFORMAT} == "elf"
PLIST=		${WRKDIR}/PLIST
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

PLIST_SUB=	EGCS_REV=${EGCS_REV} GNU_HOST=${GNUHOST}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/include/g++
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.endif
ALL_TARGET=	bootstrap
MAN1=		cccp.1 g++.1 g77.1 gcc.1

pre-patch:
	@${MV} ${WRKSRC}/gcc/config/i386/t-freebsd ${WRKSRC}/gcc/config/
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd.h ${WRKSRC}/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd-elf.h ${WRKSRC}/gcc/config/i386/freebsd.h

pre-configure:
	@(MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${SED} -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" ${FILESDIR}/freebsd.h \
		>${WRKSRC}/gcc/config/freebsd.h )
.if ${PORTOBJFORMAT} == "elf" && ${MACHINE_ARCH} == "i386"
	@${SED} -e 's/^@comment ELF-only://' ${PKGDIR}/PLIST >${PLIST}
.endif

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
		${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
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
	${MV} ${PREFIX}/bin/gcc ${PREFIX}/bin/pgcc
	${MV} ${PREFIX}/bin/g++ ${PREFIX}/bin/pg++
	${MV} ${PREFIX}/bin/g77 ${PREFIX}/bin/pg77
	${MV} ${PREFIX}/bin/gcov ${PREFIX}/bin/pgcov
	${MV} ${PREFIX}/bin/g++filt ${PREFIX}/bin/pg++filt
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}/libstdc++.a
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so*  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${EGCS_REV}
.endif
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.post.mk>
