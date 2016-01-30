# Created by: Christopher Nehren <apeiron@coitusmentis.info>
# $FreeBSD$

PORTNAME=	log4net
PORTVERSION=	1.2.10
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	APACHE/incubator/log4net/${PORTVERSION}
DISTNAME=	incubating-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port for .NET of the Apache Logging Services project

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cpe mono zip
CPE_VENDOR=	apache
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	log4net.pc
SUB_LIST=	PORTVERSION=${PORTVERSION}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE= DOCS EXAMPLES

do-install:
	@(cd ${INSTALL_WRKSRC}/bin/mono/2.0/release && ${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil /root ${STAGEDIR}${PREFIX}/lib/ /gacdir ${STAGEDIR}${PREFIX}/lib /package 2.0 /i log4net.dll)
	${INSTALL_DATA} ${WRKDIR}/log4net.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/log4net.pc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${ECHO_CMD} "Installing examples..."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
