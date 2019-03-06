# $FreeBSD$

PORTNAME=	synthv1
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	0_9_5
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school polyphonic synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libjack.so:audio/jack \
		liblo.so:audio/liblo

USES=		autoreconf gl gmake pkgconfig qt:5 shared-mime-info
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rncbc
USE_GL=		gl
USE_QT=		core gui widgets xml buildtools_build qmake_build

PLIST_SUB=	SHL3=${PORTVERSION} SHL2=${PORTVERSION:R}

CONFIGURE_ARGS=	--disable-alsa-midi

.include <bsd.port.mk>
