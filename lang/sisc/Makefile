# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	sisc
PORTVERSION=	1.16.6
PORTREVISION=	2
CATEGORIES=	lang scheme java
MASTER_SITES=	SF/${PORTNAME}/SISC/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible Java-based Scheme interpreter

LICENSE=	MPL GPLv2+
LICENSE_COMB=	dual

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|\(SISC_HOME=\).*$$|\1${DATADIR}|' \
		-e 's|\(JAVA=\)java|\1"${LOCALBASE}/bin/java" ; export JAVA_VERSION="${JAVA_VERSION}"|' \
		${WRKSRC}/sisc
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' \
		${WRKSRC}/scheme-src/srfi-22/srfi-22.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sisc ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${WRKSRC}/*.shp ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/scheme-src/*.scm ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scheme-src/srfi-22/srfi-22.sh ${STAGEDIR}${PREFIX}/bin
.for i in r4rs r5rs srfi-0 srfi-7 ieee-1178-1900
	${LN} -sf ${PREFIX}/bin/srfi-22.sh ${STAGEDIR}${PREFIX}/bin/scheme-${i}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
