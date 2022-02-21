PORTNAME=	diamond
DISTVERSIONPREFIX=	diamond-
DISTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	editors
PKGNAMESUFFIX=	-cs

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Compact programmers editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
BUILD_DEPENDS=	copperspice>=1.7:x11-toolkits/copperspice
RUN_DEPENDS=	copperspice>=1.7:x11-toolkits/copperspice

USES=		compiler:c++17-lang cmake gl gnome iconv jpeg pkgconfig ssl xorg
USE_GL=		gl
USE_GNOME=	cairo glib20 libxml2
USE_XORG=	ice sm x11 xau xcb xcursor xext xfixes xi xinerama xrandr xrender

USE_GITHUB=	yes
GH_ACCOUNT=	copperspice
GH_PROJECT=	diamond

.include <bsd.port.mk>
