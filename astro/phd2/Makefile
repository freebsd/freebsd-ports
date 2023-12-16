PORTNAME=	phd2
DISTVERSIONPREFIX=v
DISTVERSION=	2.6.10
PORTREVISION=	9
CATEGORIES=	astro

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Guiding software inspired by Stark Labs PHD Guiding
WWW=		https://openphdguiding.org/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libgmock.so:devel/googletest \
		libindidriver.so:devel/indi \
		libcurl.so:ftp/curl
RUN_DEPENDS=	indiserver:devel/indi

USES=		cmake eigen:3 gettext ninja pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	OpenPHDGuiding

USE_CXXSTD=	c++14 # googletest 1.13
USE_WX=		3.2+
USE_XORG=	x11

WX_COMPS=	wx

CMAKE_ARGS+=	-DUSE_SYSTEM_GTEST:BOOL=YES \
		-DUSE_SYSTEM_CFITSIO:BOOL=YES \
		-DUSE_SYSTEM_LIBUSB:BOOL=YES \
		-DUSE_SYSTEM_LIBINDI:BOOL=YES \
		-DUSE_SYSTEM_EIGEN3:BOOL=YES \
		-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wxgtk3u-3.2-config

.include <bsd.port.options.mk>

.if ${ARCH} != aarch64 && ${ARCH} != armv6 && ${ARCH} != armv7 && ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DOPENSOURCE_ONLY:BOOL=YES
.endif

.include <bsd.port.mk>
