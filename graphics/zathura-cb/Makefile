# $FreeBSD$

PORTNAME=	zathura-cb
PORTVERSION=	0.1.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-cb/download/ \
		http://www.madpilot.net/~mad/pwmt.org/

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Comic book plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

PLIST_FILES=	lib/zathura/cb.so share/applications/zathura-cb.desktop

USES=		compiler:c11 desktop-file-utils gmake pkgconfig libarchive ssl
USE_GNOME=	glib20 gtk30

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/cb.so

.include <bsd.port.mk>
