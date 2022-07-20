PORTNAME=	libgee
PORTVERSION=	0.6.8
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	06

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
INSTALL_TARGET=	install-strip
USES=		cpe gmake gnome libtool pathfix pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
