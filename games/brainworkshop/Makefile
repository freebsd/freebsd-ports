PORTNAME=	brainworkshop
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.3
CATEGORIES=	games python

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Dual N-Back mental exercise
WWW=		https://github.com/samcv/brainworkshop

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet1>=0:graphics/py-pyglet1@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	brain-workshop

USES=		shebangfix python:run
SHEBANG_FILES=	brainworkshop.py
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Brain Workshop" \
		"" \
		"${DATADIR}/res/misc/brain/brain.png" \
		"brainworkshop" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/brainworkshop.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/brainworkshop.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "res data" ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme* ${WRKSRC}/data/Readme* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
