PORTNAME=	gom
PORTVERSION=	0.4
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject Data Mapper
WWW=		https://wiki.gnome.org/Projects/Gom

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson pkgconfig python sqlite tar:xz
USE_GNOME=	gdkpixbuf2 glib20 introspection pygobject3

USE_LDCONFIG=	yes

.include <bsd.port.mk>
