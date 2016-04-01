# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libechonest
PORTVERSION=	2.3.1
#PORTREVISION=	0
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Collection of C++/Qt classes designed to use the APIs of The Echo Nest

LICENSE=	GPLv2

LIB_DEPENDS=	libqjson.so:devel/qjson

GH_ACCOUNT=	lfranchi

OPTIONS_DEFINE=	TEST

PLIST_SUB=	PORTVERSION=${PORTVERSION}

TEST_CMAKE_OFF=	-DECHONEST_BUILD_TESTS:BOOL=OFF
TEST_USE=	qt4=qtestlib_build

USES=		cmake pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT4=	qmake_build moc_build network rcc_build

.include <bsd.port.mk>
