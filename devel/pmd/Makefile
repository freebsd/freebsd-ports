# Created by: Alex Varju <freebsd-ports@varju.ca>
# $FreeBSD$

PORTNAME=	pmd
PORTVERSION=	5.1.3
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Static analysis tool for Java source code

LICENSE=	APACHE20 BSD4CLAUSE
LICENSE_COMB=	dual

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PORTDOCS=	*
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' \
		-e 's|LIB_DIR=$$(pwd -P)|LIB_DIR=${DATADIR}|' ${WRKSRC}/bin/run.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/run.sh ${STAGEDIR}${PREFIX}/bin/pmd
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
