PORTNAME=	bstring
DISTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/msteinert/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/msteinert/bstring/commit/
PATCHFILES=	251cf825eaf66e04736921330c8e847ffe6d9ee0.patch:-p1

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Improved string processing functionality for the C language
WWW=		https://mike.steinert.ca/bstring/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	checkmk:devel/check

USES=		meson pkgconfig tar:xz
USE_LDCONFIG=	yes

TEST_TARGET=	test

MESON_ARGS=	-Denable-tests=true

.include <bsd.port.mk>
