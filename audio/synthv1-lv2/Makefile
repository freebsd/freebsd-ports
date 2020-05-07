# $FreeBSD$

PORTNAME=	synthv1
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	0_9_14
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school polyphonic synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libjack.so:audio/jack \
		liblo.so:audio/liblo

USES=		autoreconf compiler:c++11-lang gl gmake pkgconfig qt:5 \
		shared-mime-info
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rncbc
USE_GL=		gl
USE_QT=		core gui widgets xml buildtools_build linguisttools_build qmake_build

PLIST_SUB=	SHL3=${PORTVERSION} SHL2=${PORTVERSION:R}

CONFIGURE_ARGS=	--disable-alsa-midi

BINARY_ALIAS=	qmake-qt5=${QMAKE}

.include <bsd.port.mk>
