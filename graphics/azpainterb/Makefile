# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	azpainterb
DISTVERSION=	1.1.3b2
CATEGORIES=	graphics
MASTER_SITES=	http://azsky2.html.xdomain.jp/arc/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	8-bit RGB color dot editing program

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		compiler:c11 desktop-file-utils gmake jpeg pkgconfig \
		tar:xz xorg
USE_XORG=	x11 xext xi
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" CC="${CC}"

PORTDOCS=	AUTHORS ChangeLog README README_ja manual_ja.html

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--debug
.endif

.include <bsd.port.mk>
