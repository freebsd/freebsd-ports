# $FreeBSD$

PORTNAME=	zathura-ps
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://pwmt.org/projects/zathura-ps/download/

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	PostScript support for Zathura PDF viewer

LICENSE=	zlib
LICENSE_NAME=	zlib license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libspectre.so:${PORTSDIR}/print/libspectre
BUILD_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura
RUN_DEPENDS=	zathura:${PORTSDIR}/graphics/zathura

USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	glib20 gtk30
USE_OPENSSL=	yes

PLIST_FILES=	lib/zathura/ps.so share/applications/zathura-ps.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/ps.so

.include <bsd.port.mk>
