# New ports collection makefile for:	msp430-binutils
# Date created:		15 Oct 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}.${PATCHVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		http://lev.serebryakov.spb.ru/download/msp430/:patches
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	msp430-
DISTFILES=	${PORTNAME}-${BINUTILVERSION}${EXTRACT_SUFX} \
		${PKGNAMEPREFIX}${PORTNAME}-${BINUTILVERSION}.${PATCHVERSION}${EXTRACT_SUFX}:patches

MAINTAINER=	lev@serebryakov.spb.ru

BINUTILVERSION=	2.11
PATCHVERSION=	20021028

WRKSRC=		${WRKDIR}/${PORTNAME}-${BINUTILVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure bfd/configure binutils/configure etc/configure \
		gas/configure gprof/configure ld/configure opcodes/configure
MAN1=		${PKGNAMEPREFIX}ar.1 ${PKGNAMEPREFIX}nm.1 \
		${PKGNAMEPREFIX}objdump.1 ${PKGNAMEPREFIX}ranlib.1 \
		${PKGNAMEPREFIX}size.1 ${PKGNAMEPREFIX}strings.1 \
		${PKGNAMEPREFIX}strip.1 ${PKGNAMEPREFIX}objcopy.1 \
		${PKGNAMEPREFIX}addr2line.1 ${PKGNAMEPREFIX}nlmconv.1 \
		${PKGNAMEPREFIX}c++filt.1 ${PKGNAMEPREFIX}as.1 \
		${PKGNAMEPREFIX}ld.1

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt gasp ld nm objcopy objdump ranlib \
		readelf size strings strip

post-install:
.for F in ${BINARIES}
	@strip ${PREFIX}/bin/${PKGNAMEPREFIX}$F
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor
	@cd ${PREFIX}/lib ; ${MV} libbfd.a lib${PKGNAMEPREFIX}bfd.a
	@cd ${PREFIX}/lib ; ${MV} libopcodes.a lib${PKGNAMEPREFIX}opcodes.a

.include <bsd.port.mk>
