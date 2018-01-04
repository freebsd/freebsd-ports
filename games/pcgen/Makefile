# $FreeBSD$

PORTNAME=	pcgen
PORTVERSION=	6.02.1
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/PCGen%20Stable/${PORTVERSION}
DISTNAME=	pcgen${PORTVERSION:S/.//g}_full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java-based RPG character generator and maintenance program

LICENSE=	LGPL21

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	pcgen.sh

PLIST_FILES=	bin/pcgen
PORTDATA=	*
PORTDOCS=	*
PLIST_DIRS=	%%DATADIR%%/characters

OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "batch-convert.jar characters data filepaths.ini lib \
		logging.properties outputsheets pcgen.jar plugins preview system" ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/pcgen.sh ${STAGEDIR}${PREFIX}/bin/pcgen

do-install-DOCS-on:
	cd "${WRKSRC}/docs" && ${COPYTREE_SHARE} . "${STAGEDIR}${DOCSDIR}"
	${INSTALL_DATA} "${WRKSRC}"/*.html "${STAGEDIR}${DOCSDIR}"

.include <bsd.port.mk>
