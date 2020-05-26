# $FreeBSD$

PORTNAME=	beatslash
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugins to mangle, slash, repeat and do much more with your beats

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to build: FileNotFoundError: [Errno 2] No such file or directory

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lvtk>0:audio/lvtk
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gnome pkgconfig waf
USE_GITHUB=	yes
GH_ACCOUNT=	blablack
GH_PROJECT=	${PORTNAME}-lv2
USE_GNOME=	atkmm gdkpixbuf2 gtkmm24

post-patch:
	@${REINPLACE_CMD} -e 's|#include <lvtk-1/lvtk|#include <lvtk-2/lvtk|' ${WRKSRC}/src/*.?pp

.include <bsd.port.mk>
