# New ports collection makefile for:	quackle
# Date created:			15 Feb 2008
# Whom:				shoemaker@bluebottle.com (Jonathan Shoemaker)
#
# $FreeBSD$
#

PORTNAME=	quackle
PORTVERSION=	0.95
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://web.mit.edu/jasonkb/www/quackle/downloads/${PORTNAME}-${PORTVERSION}/
DISTFILES=	${PORTNAME}-${PORTVERSION}-source.tar.gz

MAINTAINER=	shoemaker@bluebottle.com
COMMENT=	A scrabble-like word game utilizing qt4

USE_SCONS=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build gui
USE_GMAKE=	yes
QMAKE_ARGS=	-unix -spec ${QMAKESPEC}

pre-patch:
	@${REINPLACE_CMD} -e 's|if (QFile::exists("data"))|if (QFile::exists("${DATADIR}"))|' ${WRKSRC}/quacker/settings.cpp
	@${REINPLACE_CMD} -e 's|QUACKLE_DATAMANAGER->setDataDirectory("data");|QUACKLE_DATAMANAGER->setDataDirectory("${DATADIR}");|' ${WRKSRC}/quacker/settings.cpp

post-build:
	@(cd ${WRKSRC}/quackleio && ${QMAKE} ${QMAKE_ARGS} -o Makefile quackleio.pro && ${SETENV} ${MAKE_ENV} ${GMAKE} && cd ${WRKSRC}/quacker && ${QMAKE} ${QMAKE_ARGS} -o Makefile quacker.pro && ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/quacker/quacker ${PREFIX}/bin/quackle
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR})

.include <bsd.port.mk>
