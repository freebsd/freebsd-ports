# $FreeBSD$

PORTNAME=	libkdegames
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	games kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries used by KDE 4 games

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		network phonon xml moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		LOWLATENCY
OPTIONS_DEFAULT=	LOWLATENCY

LOWLATENCY_DESC=	Use OpenAL and libsndfile for lower latency
LOWLATENCY_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
LOWLATENCY_USES=	openal
LOWLATENCY_CMAKE_ON=	-DWITH_OpenAL=on \
			-DWITH_SndFile=on
LOWLATENCY_CMAKE_OFF=	-DWITH_OpenAL=off \
			-DWITH_SndFile=off

.include <bsd.port.mk>
