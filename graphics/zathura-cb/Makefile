# $FreeBSD$

PORTNAME=	zathura-cb
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura-cb/download/

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Comic book plugin for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

PLIST_FILES=	lib/zathura/cb.so share/applications/zathura-cb.desktop

USES=		compiler:c11 desktop-file-utils gmake pkgconfig libarchive
USE_GNOME=	glib20 gtk30
USE_OPENSSL=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/cb.so

.include <bsd.port.mk>
