PORTNAME=	pcgen
PORTVERSION=	6.06.01
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	https://github.com/PCGen/${PORTNAME}/releases/download/${PORTVERSION}/
DISTNAME=	pcgen-${PORTVERSION}-full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java-based RPG character generator and maintenance program

LICENSE=	LGPL21

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_JAVA=	yes
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
	cd ${WRKSRC} && ${COPYTREE_SHARE} "pcgen-batch-convert.jar characters data libs \
		logging.properties outputsheets pcgen.jar plugins preview system" ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/pcgen.sh ${STAGEDIR}${PREFIX}/bin/pcgen

do-install-DOCS-on:
	cd "${WRKSRC}/docs" && ${COPYTREE_SHARE} . "${STAGEDIR}${DOCSDIR}"

.include <bsd.port.mk>
