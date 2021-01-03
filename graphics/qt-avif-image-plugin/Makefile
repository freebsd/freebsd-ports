# $FreeBSD$

PORTNAME=	qt-avif-image-plugin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt image plugin to read/write AV1 Image File Format (AVIF)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Part of graphics/kf5-kimageformats since 5.78
EXPIRATION_DATE=	2021-03-31

LIB_DEPENDS=	libavif.so:graphics/libavif

USES=		cmake compiler:c++14-lang kde:5 qt:5
USE_GITHUB=	yes
USE_KDE=	ecm_build
USE_QT=		qmake_build buildtools_build core gui
GH_ACCOUNT=	novomesk
PLIST_FILES=	${QT_PLUGINDIR}/imageformats/libqavif.so \
		share/kservices5/qimageioplugins/avif.desktop \
		share/kservices5/qimageioplugins/avifs.desktop \
		${NULL}

.include <bsd.port.mk>
