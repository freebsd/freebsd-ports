# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	singularity
PORTVERSION=	0.30c
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	endgame-
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulates the life of a true AI

RUN_DEPENDS=	py*-game>=1.8:${PORTSDIR}/devel/py-game \
		${PYNUMPY}

USE_PYDISTUTILS=yes
USE_PYTHON=	yes
USE_SDL=	image mixer
PORTDOCS=	AUTHORS Changelog README.txt TODO
PROJECTHOST=	${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	MUSIC DOCS
OPTIONS_DEFAULT=	MUSIC
MUSIC_DESC=	Install original music pack

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMUSIC}
RUN_DEPENDS+=	endgame-singularity-music>=006:${PORTSDIR}/games/endgame-singularity-music
.endif

post-extract:
	@${FIND} ${WRKSRC} -name '*.pyc' -delete
	@cd ${WRKSRC}/&&${MV} code ${PORTNAME}
	@${MKDIR} ${WRKSRC}/data/music/
	@${TOUCH} ${WRKSRC}/data/music/.keep_me

post-patch:
	@${REINPLACE_CMD} -e '5,16d;25,31d;\
		/app=/s|app=.*|packages=["singularity","singularity/graphics","singularity/screens"],|;\
		/name=/s|".*"|"singularity"|' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e '/import cPickle/s|cPickle|pickle as cPickle|' \
		${WRKSRC}/${PORTNAME}/g.py
	@${REINPLACE_CMD} -e '/data_loc = /s|=.*|= "${DATADIR}/"|;\
		/data_loc.*music/s|, ".."||' ${WRKSRC}/${PORTNAME}/g.py
	@${REINPLACE_CMD} -e '/ code\.[a-z]/s|code|singularity|' \
		${WRKSRC}/${PORTNAME}/graphics/button.py \
		${WRKSRC}/${PORTNAME}/graphics/dialog.py \
		${WRKSRC}/${PORTNAME}/graphics/g.py \
		${WRKSRC}/${PORTNAME}/screens/base.py \
		${WRKSRC}/${PORTNAME}/screens/finance.py \
		${WRKSRC}/${PORTNAME}/screens/main_menu.py \
		${WRKSRC}/${PORTNAME}/screens/options.py
	@${REINPLACE_CMD} -e '/ code/s|code|singularity|' \
		${WRKSRC}/${PORTNAME}/screens/knowledge.py \
		${WRKSRC}/${PORTNAME}/screens/location.py \
		${WRKSRC}/${PORTNAME}/screens/research.py
	@${REINPLACE_CMD} -e '/ code[ \.]/s|code|singularity|' \
		${WRKSRC}/${PORTNAME}/screens/map.py

post-build:
	@${ECHO_CMD} '#!${PYTHON_CMD}' > ${WRKSRC}/${PORTNAME}.py
	@${ECHO_CMD} 'import ${PORTNAME}.${PORTNAME}' >> ${WRKSRC}/${PORTNAME}.py

post-install:
	@cd ${WRKSRC}/data/&&${COPYTREE_SHARE} . ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
