# New ports collection makefile for:	kcheckers
# Date created: 			2004-01-08
# Whom: 				arved
#
# $FreeBSD$

PORTNAME=	kcheckers
PORTVERSION=	0.8.1
CATEGORIES=	games
MASTER_SITES=	SF/qcheckers/${PORTNAME}/${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Qt version of the classic boardgame checkers

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qmake_build moc_build rcc_build
MAKE_ENV=	QTDIR="${QT_PREFIX}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/common.h
	@${REINPLACE_CMD} -e 's|..PREFIX/share/kcheckers|${DATADIR}|' \
		-e 's|..PREFIX|${PREFIX}|' ${WRKSRC}/kcheckers.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} ${QMAKEFLAGS} kcheckers.pro

.include <bsd.port.mk>
