# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libechonest
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Collection of C++/Qt classes designed to use the APIs of The Echo Nest

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libqjson.so:devel/qjson@qt4

GH_ACCOUNT=	lfranchi

OPTIONS_DEFINE=	TEST

PLIST_SUB=	PORTVERSION=${PORTVERSION}

TEST_CMAKE_BOOL=ECHONEST_BUILD_TESTS
TEST_USE=	qt=qtestlib_build,xml_build

USES=		cmake pkgconfig qt:4
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		corelib qmake_build moc_build network rcc_build

.include <bsd.port.mk>
