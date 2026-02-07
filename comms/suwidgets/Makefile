PORTNAME=	suwidgets
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sigutils-related widgets
WWW=		https://github.com/BatchDrake/SuWidgets

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libsigutils.so:comms/sigutils

USES=		gl pkgconfig qmake qt:5
USE_QT=		core designer gui opengl widgets xml buildtools:build
USE_GL=		gl
USE_LDCONFIG=	yes

QMAKE_SOURCE_PATH=	${WRKSRC}/SuWidgets.pro

USE_GITHUB=	yes
GH_ACCOUNT=	BatchDrake
GH_PROJECT=	SuWidgets

.include <bsd.port.mk>
