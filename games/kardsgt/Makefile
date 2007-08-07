# New ports collection makefile for:	kardsgt
# Date created:		8 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kardsgt
PORTVERSION=	0.6.3
CATEGORIES=	games
MASTER_SITES=	SAVANNAH CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Card game suite

USE_QT_VER=	3
MAKE_ENV=	DATADIR=${DATADIR} DOCSDIR=${DOCSDIR} QTDIR="${QT_PREFIX}"
MAKE_ARGS=	bindir=${PREFIX}/bin mandir=${MANPREFIX}/man\
		datadir=${PREFIX}/share
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
MAN6=	${PORTNAME}.6

post-patch:
	@${REINPLACE_CMD} -e 's|$${datadir}/kardsgt-$${VERSION}|$${DATADIR}|;\
		s|$${docdir}/kardsgt-$${VERSION}|$${DOCSDIR}|;\
		s|qmake|${SETENV} ${MAKE_ENV} qmake -spec ${QMAKESPEC}|;\
		s|--parents|-p|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
