# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	gnome-autoar
DISTVERSION=	0.3.1
CATEGORIES=	archivers
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib wrapper around libarchives

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

USES=		gettext-runtime gmake gnome libarchive libtool pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
