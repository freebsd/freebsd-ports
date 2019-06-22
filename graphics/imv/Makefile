# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	imv
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple image viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	asciidoc:textproc/asciidoc
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		librsvg-2.so:graphics/librsvg2
TEST_DEPENDS=	${LOCALBASE}/lib/libcmocka.so:sysutils/cmocka

USES=		desktop-file-utils gmake gnome \
		localbase pkgconfig sdl
USE_SDL=	sdl2 ttf2
USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	eXeC64

ALL_TARGET=	imv
TEST_TARGET=	check

MAKE_ARGS=	V=1

PLIST_FILES=	bin/imv \
		etc/imv_config \
		man/man1/imv.1.gz \
		man/man5/imv.5.gz \
		share/applications/imv.desktop

.include <bsd.port.mk>
