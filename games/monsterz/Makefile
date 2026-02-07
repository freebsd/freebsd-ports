PORTNAME=	monsterz
PORTVERSION=	0.9
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Arcade puzzle game
WWW=		https://github.com/0-wiz-0/monsterz

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYGAME}

USE_GITHUB=	yes
GH_ACCOUNT=	0-wiz-0

USES=		python shebangfix
SHEBANG_FILES=	monsterz.py
MAKE_ENV=	prefix=${PREFIX}

PORTDOCS=	AUTHORS README.md TODO

SCOREDIR=	/var/games
PLIST_SUB=	SCOREDIR=${SCOREDIR}

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} '/test -f/ s|scorefile)|&.sample|g' \
		${WRKSRC}/Makefile

post-install:
.for d in graphics sound
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${DATADIR}
	(cd ${STAGEDIR}${PREFIX}	\
	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${DATADIR}	\
		-f ${DATADIR:S;${PREFIX}/;;}	\
	&& ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d ${DATADIR}\
		-f ${DATADIR:S;${PREFIX}/;;})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/monsterz

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
