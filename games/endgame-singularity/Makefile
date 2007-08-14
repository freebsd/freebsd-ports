# New ports collection makefile for:	endgame-singularity
# Date created:		10 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	singularity
PORTVERSION=	0.26.0.1
DISTVERSION=	0.26a
CATEGORIES=	games
MASTER_SITES=	http://emhsoft.com/singularity/ CENKES
PKGNAMEPREFIX=	endgame-
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Simulates the life of a true AI

RUN_DEPENDS=	py*-game>=1.7.1:${PORTSDIR}/devel/py-game

USE_PYDISTUTILS=yes
USE_PYTHON=	yes
USE_SDL=	image mixer
PYDISTUTILS_PKGVERSION=	${DISTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
PORTDOCS=	AUTHORS Changelog README.txt TODO

post-extract:
	@${FIND} ${WRKSRC} -name '*.pyc' -delete
	@cd ${WRKSRC}/&&${MV} code ${PORTNAME}
	@${MKDIR} ${WRKSRC}/data/music/
	@${TOUCH} ${WRKSRC}/data/music/.keep_me

post-patch:
	@${REINPLACE_CMD} -e '/py2exe/d;s|console.*|packages=["${PORTNAME}"],|;\
		/name=/s|=.*|="${PORTNAME}",|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e '/data_loc = /s|=.*|= "${DATADIR}/"|;\
		/musicpath/s|, ".."||' ${WRKSRC}/${PORTNAME}/g.py

post-build:
	@${ECHO_CMD} '#!${PYTHON_CMD}' > ${WRKSRC}/${PORTNAME}.py
	@${ECHO_CMD} 'import ${PORTNAME}.${PORTNAME}' >> ${WRKSRC}/${PORTNAME}.py

post-install:
	@cd ${WRKSRC}/data/&&${COPYTREE_SHARE} . ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
