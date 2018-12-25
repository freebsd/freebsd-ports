# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grantlee
DISTVERSION=	${GRANTLEE_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.${PORTNAME}.org/ \
		http://www.loegria.net/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	String template engine for Qt 4

LICENSE=	LGPL21

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

PORTSCOUT=	limit:^0\.

USE_QT=		corelib gui qtestlib_build script \
		qmake_build moc_build rcc_build uic_build
USES=		cmake grantlee:4,selfbuild qt:4
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=FALSE
USE_LDCONFIG=	yes

.include <bsd.port.mk>
