# New ports collection makefile for:	monsterz
# Date created:		Fri 29 apr 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	monsterz
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	http://sam.zoy.org/monsterz/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Monsterz - arcade puzzle game

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
NO_BUILD=	yes

LINSTDIR?=	share/games/${PORTNAME}
INSTDIR=	${PREFIX}/${LINSTDIR}
PLIST_SUB=	LINSTDIR=${LINSTDIR}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS COPYING INSTALL README TODO

do-install:
	${MKDIR} ${INSTDIR}/graphics ${INSTDIR}/sound
	${INSTALL_SCRIPT} ${WRKSRC}/monsterz.py ${INSTDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${INSTDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${INSTDIR}
.for sd in graphics sound
	${FIND} ${WRKSRC}/${sd} -type f -exec ${INSTALL_DATA} {} ${INSTDIR}/${sd} \;
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
