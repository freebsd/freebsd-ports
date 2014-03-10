# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	funnyboat
PORTVERSION=	1.5
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A side scrolling shooter game starring a steamboat on the sea

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		zip
USE_PYTHON=	yes
NO_BUILD=	yes

SUB_FILES=	funnyboat_
SUB_LIST=	PROGRAM_DIR="${PREFIX}/lib/${PORTNAME}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.py data" ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/funnyboat_ ${STAGEDIR}${PREFIX}/bin/funnyboat
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
