# New ports collection makefile for:	kcheckers
# Date created: 			2004-01-08
# Whom: 				arved
#
# $FreeBSD$

PORTNAME=	kcheckers
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	http://kcheckers.osdn.org.ua/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Qt version of the classic boardgame checkers

WRKSRC=		${WRKDIR}/kcheckers
USE_QT_VER=	3
MAKE_ENV=	QTDIR="${X11BASE}"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${PREFIX}/share/qt/mkspecs/freebsd-g++ kcheckers.pro

.include <bsd.port.mk>
