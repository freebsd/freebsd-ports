PORTNAME=	libgnome-games-support
DISTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small library intended for internal use by GNOME Games
WWW=		https://git.gnome.org/browse/libgnome-games-support

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee

PORTSCOUT=	limitw:1,even

USES=		gettext gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf2 gtk30

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
