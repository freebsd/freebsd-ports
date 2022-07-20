PORTNAME=	libgee
PORTVERSION=	0.20.3
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

PORTSCOUT=	limitw:1,even

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USES=		cpe gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

.include <bsd.port.mk>
