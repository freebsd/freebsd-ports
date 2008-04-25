# New ports collection makefile for:	quackle
# Date created:			15 Feb 2008
# Whom:				shoemaker@bluebottle.com (Jonathan Shoemaker)
#
# $FreeBSD$
#

PORTNAME=	quackle
PORTVERSION=	0.95
CATEGORIES=	games
MASTER_SITES=	http://web.mit.edu/jasonkb/www/quackle/downloads/${PORTNAME}-${PORTVERSION}/
DISTFILES=	${PORTNAME}-${PORTVERSION}-source.tar.gz

MAINTAINER=	shoemaker@bluebottle.com
COMMENT=	A scrabble-like word game utilizing qt4

USE_SCONS=	yes
USE_QT_VER=	4
USE_GMAKE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|if (QFile::exists("data"))|if (QFile::exists("${PREFIX}/lib/quackle"))|' ${WRKSRC}/quacker/settings.cpp
	@${REINPLACE_CMD} -e 's|QUACKLE_DATAMANAGER->setDataDirectory("data");|QUACKLE_DATAMANAGER->setDataDirectory("${PREFIX}/lib/quackle");|' ${WRKSRC}/quacker/settings.cpp

post-build:
	@(cd ${WRKSRC}/quackleio && qmake-qt4 -unix -spec freebsd-g++ -o Makefile quackleio.pro && ${GMAKE} && cd ${WRKSRC}/quacker && qmake-qt4 -unix -spec freebsd-g++ -o Makefile quacker.pro && ${GMAKE})

do-install:
	@(${MKDIR} -m 555 ${PREFIX}/lib/quackle; cd ${WRKSRC}/data && ${PAX} -rw ./ ${PREFIX}/lib/quackle)
	@${FIND} ${PREFIX}/lib/quackle -type directory -exec ${CHMOD} 555 {} \;
	@${FIND} ${PREFIX}/lib/quackle -type file -exec ${CHMOD} 444 {} \;
	@${INSTALL} -m 0555 ${WRKSRC}/quacker/quacker ${PREFIX}/bin/quackle

.include <bsd.port.mk>
