PORTNAME=	suil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.26
CATEGORIES=	audio

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	C library for loading and wrapping LV2 plugin UIs
WWW=		https://gitlab.com/lv2/suil

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_RUN_DEPENDS=	lv2>=1.14.0:audio/lv2

USES=		compiler:c++17-lang gnome meson pkgconfig qt:6 xorg
USE_GITLAB=	yes
GL_ACCOUNT=	lv2
USE_LDCONFIG=	yes
PLIST_SUB=	SUILVERSION=${DISTVERSION}

MESON_ARGS=	-Ddocs=disabled \
		-Dqt5=disabled \
		-Dtests=enabled \
		-Dx11=enabled

USE_XORG=	x11

OPTIONS_DEFINE=	GTK2 GTK3 QT6
OPTIONS_DEFAULT=	GTK3 QT6
OPTIONS_SUB=	yes

GTK2_USE=	gnome=gtk20
GTK2_MESON_ENABLED=	gtk2

GTK3_USE=	gnome=gtk30
GTK3_MESON_ENABLED=	gtk3

QT6_USE=	qt=base
QT6_MESON_ENABLED=	qt6

.include <bsd.port.mk>
