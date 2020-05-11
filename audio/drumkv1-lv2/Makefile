# $FreeBSD$

PORTNAME=	drumkv1
DISTVERSION=	0.9.14
CATEGORIES=	audio multimedia
MASTER_SITES=	SF
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school drum-kit sampler: LV2 plugin and Jack app

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		liblo.so:audio/liblo

USES=		compiler:c++11-lang gl gmake localbase:ldflags pkgconfig qt:5 shared-mime-info
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa-midi
USE_QT=		core gui widgets xml buildtools_build linguisttools_build qmake_build
USE_GL=		gl
USE_LDCONFIG=	yes

BINARY_ALIAS=	qmake-qt5=${QMAKE}

.include <bsd.port.mk>
