PORTNAME=	snpeff
DISTVERSION=	5.0
CATEGORIES=	biology java python
MASTER_SITES=	https://snpeff.blob.core.windows.net/versions/
DISTNAME=	snpEff_latest_core
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genetic variant annotation and effect prediction toolbox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		python:3.6+ shebangfix zip
USE_JAVA=	yes

JAVA_VERSION=	12+
SHEBANG_FILES=	scripts/* scripts/gsa/*

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/snpEff

LIBEXEC_DIR=	${PREFIX}/libexec/snpeff

pre-configure:
	${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' \
			 -e 's|%%JAVA_HOME%%|${JAVA_HOME}|g' \
			 ${WRKSRC}/scripts/snpEff ${WRKSRC}/scripts/snpSift

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/snpeff
	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/snpEff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/snpSift ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${JAVAJARDIR}/snpeff
	${INSTALL_DATA} ${WRKSRC}/*.config ${STAGEDIR}${JAVAJARDIR}/snpeff
	cd ${WRKSRC}/scripts && ${COPYTREE_BIN} . ${STAGEDIR}${LIBEXEC_DIR}

.include <bsd.port.mk>
