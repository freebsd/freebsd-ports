# Created by: Alex Varju <freebsd-ports@varju.ca>
# $FreeBSD$

PORTNAME=	pmd
PORTVERSION=	5.6.1
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Static analysis tool for Java source code

LICENSE=	APACHE20 BSD4CLAUSE
LICENSE_COMB=	dual

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' \
		-e 's|LIB_DIR=$$(pwd -P)|LIB_DIR=${DATADIR}|' ${WRKSRC}/bin/run.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/run.sh ${STAGEDIR}${PREFIX}/bin/pmd
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
