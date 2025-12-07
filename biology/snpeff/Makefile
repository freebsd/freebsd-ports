PORTNAME=	snpeff
DISTVERSION=	5.1
CATEGORIES=	biology java python
MASTER_SITES=	https://snpeff.blob.core.windows.net/versions/
DISTNAME=	snpEff_latest_core
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genetic variant annotation and effect prediction toolbox
WWW=		https://snpeff.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN=		Unfetchable
EXPIRATION_DATE=2026-01-31

RUN_DEPENDS=	bash:shells/bash

USES=		java python shebangfix zip

JAVA_VERSION=	17+
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
