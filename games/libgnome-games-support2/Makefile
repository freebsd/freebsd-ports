PORTNAME=	libgnome-games-support
DISTVERSION=	2.0.2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small library intended for internal use by GNOME Games
WWW=		https://gitlab.gnome.org/GNOME/libgnome-games-support

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee

USES=		gettext-tools gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 gtk40

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
