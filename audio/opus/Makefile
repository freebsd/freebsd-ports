# $FreeBSD$

PORTNAME=	opus
PORTVERSION=	1.1.4
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/ \
		MOZILLA/opus

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	IETF audio codec

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake libtool pathfix
CPE_VENDOR=	opus-codec
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-custom-modes \
		--disable-maintainer-mode \
		--disable-doc   # requires doxygen
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.options.mk>

# i386: needs cpuid instruction; arm: only floating point
.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--enable-intrinsics
.endif

.if ${ARCH} == "arm"
CONFIGURE_ARGS+=--enable-fixed-point
.endif

.include <bsd.port.mk>
