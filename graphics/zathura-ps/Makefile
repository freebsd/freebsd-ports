# $FreeBSD$

PORTNAME=	zathura-ps
PORTVERSION=	0.2.3
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura-ps/download/

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	PostScript support for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libspectre.so:print/libspectre
BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c11 desktop-file-utils gmake pkgconfig
USE_GNOME=	glib20 gtk30
USE_OPENSSL=	yes

PLIST_FILES=	lib/zathura/ps.so share/applications/zathura-ps.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/ps.so

.include <bsd.port.mk>
