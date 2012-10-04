# Created by:			Martin Otto
#
# $FreeBSD$

PORTNAME=	CastleVox
PORTVERSION=	1.2
CATEGORIES=	games java
MASTER_SITES=	http://sillysoft.net/download/
DISTNAME=	CastleVox-linux

MAINTAINER=	gamato@users.sf.net
COMMENT=	A fast world domination game

FETCH_ARGS=	-Fpr
USE_JAVA=	yes
JAVA_VERSION=	1.6+

WRKSRC=		${WRKDIR}/CastleVoxPC
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	CastleVox

do-install:
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \*.jar ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/VoxIcon.png ${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} Support ${DATADIR})
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} docs ${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/CastleVox ${PREFIX}/bin

.include <bsd.port.mk>
