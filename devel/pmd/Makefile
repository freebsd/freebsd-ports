# Created by: Alex Varju <freebsd-ports@varju.ca>
# $FreeBSD$

PORTNAME=	pmd
PORTVERSION=	5.0.5
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Static analysis tool for Java source code

LICENSE=	BSD

USE_ZIP=	yes
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

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/run.sh ${PREFIX}/bin/pmd
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
