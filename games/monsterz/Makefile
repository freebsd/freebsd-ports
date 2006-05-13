# New ports collection makefile for:	monsterz
# Date created:		Fri 29 apr 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	monsterz
PORTVERSION=	0.7.0
CATEGORIES=	games
MASTER_SITES=	http://sam.zoy.org/monsterz/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Monsterz - arcade puzzle game

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
MAKE_ENV=	prefix=${PREFIX}

SCOREDIR=	/var/games
PLIST_SUB=	SCOREDIR=${SCOREDIR}

PORTDOCS=	AUTHORS COPYING INSTALL README TODO

post-install:
	${STRIP_CMD} ${PREFIX}/games/monsterz
	${LN} -sf ${PREFIX}/games/monsterz ${PREFIX}/bin
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/games/monsterz
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/games/monsterz
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
