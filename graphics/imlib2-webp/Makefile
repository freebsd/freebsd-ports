PORTNAME=	imlib2-webp
PORTVERSION=	20230222
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	WebP image loader plugin for Imlib 2
WWW=		https://www.hauweele.net/~gawen/imlib2-webp.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	webp support is handled by graphics/imlib2 and it is enabled by default.
EXPIRATION_DATE=	2026-02-28
BROKEN=		pkg-static: imlib2-webp-20230222_3 conflicts with imlib2-1.12.6,2 (installs files into the same place).  Problematic file: /usr/local/lib/imlib2/loaders/webp.so

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libwebp.so:graphics/webp

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	gawen947
GH_TAGNAME=	d7a8b758576

CONFLICTS_INSTALL=	imlib2

PLIST_FILES=	lib/imlib2/loaders/webp.so

.include <bsd.port.mk>
