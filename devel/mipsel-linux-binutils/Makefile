# New ports collection makefile for:	mipsel-linux-binutils
# Date created:		13 June 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.10.91
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/agenda/
PKGNAMEPREFIX=	mipsel-linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}-cvs

MAINTAINER=	lev@FreeBSD.org
COMMENT=	GNU binutils for mipsel-linux cross-development with SNOW ABI

WRKSRC=		${WRKDIR}/binutils-CVS/src

USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} --with-gnu-ld --with-gnu-as \
		--with-gcc --without-x11
USE_INC_LIBTOOL_VER=	13
LIBTOOLFILES=	configure bfd/configure binutils/configure etc/configure \
		gas/configure gprof/configure ld/configure opcodes/configure
MAN1=		${PKGNAMEPREFIX}ar.1 ${PKGNAMEPREFIX}nm.1 \
		${PKGNAMEPREFIX}objdump.1 \
		${PKGNAMEPREFIX}ranlib.1 ${PKGNAMEPREFIX}size.1 \
		${PKGNAMEPREFIX}strings.1 ${PKGNAMEPREFIX}strip.1 \
		${PKGNAMEPREFIX}objcopy.1 ${PKGNAMEPREFIX}addr2line.1 \
		${PKGNAMEPREFIX}nlmconv.1 ${PKGNAMEPREFIX}c++filt.1 \
		${PKGNAMEPREFIX}as.1 ${PKGNAMEPREFIX}ld.1

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt gasp ld nm objcopy objdump ranlib \
		readelf size strings strip

post-install:
.for F in ${BINARIES}
	@${STRIP_CMD} ${PREFIX}/bin/${PKGNAMEPREFIX}$F
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.mk>
