# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brainworkshop
PORTVERSION=	5.0.git20191222
CATEGORIES=	games python

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Dual N-Back mental exercise

LICENSE=	GPLv1+ # version not specified

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyglet/__init__.py:graphics/py-pyglet@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	samcv
GH_TAGNAME=	f1e28d0

USES=		shebangfix python:run
SHEBANG_FILES=	brainworkshop.pyw
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
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/brainworkshop.pyw

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/brainworkshop.pyw ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "res data" ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme* ${WRKSRC}/data/Readme* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
