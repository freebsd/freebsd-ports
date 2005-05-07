# New ports collection makefile for:	kcheckers
# Date created: 			2004-01-08
# Whom: 				arved
#
# $FreeBSD$

PORTNAME=	kcheckers
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	http://kcheckers.osdn.org.ua/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt version of the classic boardgame checkers

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${X11BASE}"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${PREFIX}/share/qt/mkspecs/freebsd-g++ kcheckers.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kcheckers ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/kcheckers.pdn ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README AUTHORS ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
