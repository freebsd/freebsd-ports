PORTNAME=	funnyboat
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Side scrolling shooter game starring a steamboat on the sea
WWW=		https://github.com/AMDmi3/funnyboat \
		https://funnyboat.sourceforge.net/

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE-CODE.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MEDIA.txt

RUN_DEPENDS=	${PYGAME}

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3

USES=		python:run  # version range inherited from numpy
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	funnyboat.sh
SUB_LIST=	DATADIR="${DATADIR}" PYTHON_CMD="${PYTHON_CMD}"

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/funnyboat

OPTIONS_DEFINE=	DOCS

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "*.py data" ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/funnyboat.sh ${STAGEDIR}${PREFIX}/bin/funnyboat

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
