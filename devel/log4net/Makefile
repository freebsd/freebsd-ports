# Created by: Christopher Nehren <apeiron@coitusmentis.info>
# $FreeBSD$

PORTNAME=	log4net
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	incubator/log4net/${PORTVERSION}
DISTNAME=	incubating-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Port for .NET of the Apache Logging Services project

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_ZIP=	yes
NO_BUILD=	yes

SUB_FILES=	log4net.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION}

.if !defined (NOPORTDOCS)
PORTDOCS=	*
.endif
.if !defined (NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

NO_STAGE=	yes
do-install:
	@(cd ${INSTALL_WRKSRC}/bin/mono/2.0/release && ${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil /root ${PREFIX}/lib/ /gacdir ${PREFIX}/lib /package 2.0 /i log4net.dll)
	${INSTALL_DATA} ${WRKDIR}/log4net.pc ${PREFIX}/libdata/pkgconfig/log4net.pc
.if !defined (NOPORTDOCS)
	@${ECHO_CMD} "Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined (NOPORTEXAMPLES)
	@${ECHO_CMD} "Installing examples..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
