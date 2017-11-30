# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	funnyboat
PORTVERSION=	1.5
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Side scrolling shooter game starring a steamboat on the sea

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE-CODE.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MEDIA.txt

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:devel/py-game

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		python:2.7,run zip
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	funnyboat_
SUB_LIST=	PROGRAM_DIR="${PREFIX}/lib/${PORTNAME}" PYTHON_CMD="${PYTHON_CMD}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "*.py data" ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/funnyboat_ ${STAGEDIR}${PREFIX}/bin/funnyboat

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
