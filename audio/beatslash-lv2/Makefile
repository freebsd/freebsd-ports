# $FreeBSD$

PORTNAME=	beatslash
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugins to mangle, slash, repeat and do much more with your beats

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to configure
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

DEPRECATED=	Unmaintained and doesn't build with the latest audio/lvtk version 2.x
EXPIRATION_DATE=2021-02-28

post-patch:
	@${REINPLACE_CMD} -e 's|#include <lvtk-1/lvtk|#include <lvtk-2/lvtk|' ${WRKSRC}/src/*.?pp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/beatslash.lv2/*.so

.include <bsd.port.mk>
