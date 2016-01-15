# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	lensfun
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for fixing lens geometry distortions

LICENSE=	LGPL3

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

USES=		cmake pkgconfig tar:bzip2
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DBUILD_AUXFUN:BOOL=ON -DINSTALL_HELPER_SCRIPTS:BOOL=OFF

OPTIONS_DEFINE=	SIMD
OPTIONS_DEFAULT=	SIMD

SIMD_CMAKE_OFF=	-DBUILD_FOR_SSE:BOOL=OFF -DBUILD_FOR_SSE2:BOOL=OFF

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/s,$${LIBDIR},libdata,' \
		${WRKSRC}/libs/lensfun/CMakeLists.txt

.include <bsd.port.mk>
