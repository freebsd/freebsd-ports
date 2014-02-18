# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

# Some ports install files into versioned grantlee directory (GRANTLEE_VER)
# they must be fixed whenever grantlee gets version bump
# Known ports:
# deskutils/kdepim4
# devel/kdevplatform
# finance/skrooge
# misk/kdehier4
#

PORTNAME=	grantlee
DISTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	http://downloads.${PORTNAME}.org/ \
		http://www.loegria.net/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	String template engine for Qt 4

LICENSE=	LGPL21

USE_QT4=	corelib gui qtestlib_build script \
		qmake_build moc_build rcc_build uic_build
USES=		cmake:outsource
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=FALSE
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		GRANTLEE_VER=${PORTVERSION:R}

.include <bsd.port.mk>
