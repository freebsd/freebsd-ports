# Created by: glarkin
# $FreeBSD$

PORTNAME=	statsvn
PORTVERSION=	0.7.0
PORTREVISION=	5
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subversion repository activity report generator

LICENSE=	LGPL21+

RUN_DEPENDS=	subversion>=1.3:devel/subversion

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USES=		zip
USE_JAVA=	yes
USE_ANT=	yes
NO_ARCH=	yes

ALL_TARGET=	dist

SUB_FILES=	statsvn
SUB_LIST=	JAVA=${JAVA}

PORTDOCS=	*
PLIST_FILES=	bin/statsvn \
		%%DATADIR%%/statsvn.jar

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	javadoc

do-install:
	(cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/statsvn ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
