# Created by: Christopher Nehren <apeiron@coitusmentis.info>
# $FreeBSD$

PORTNAME=	log4net
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	incubator/log4net/${PORTVERSION}
DISTNAME=	incubating-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port for .NET of the Apache Logging Services project

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		mono zip
NO_BUILD=	yes
SUB_FILES=	log4net.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION}
OPTIONS_DEFINE= DOCS EAMPLES

do-install:
	@(cd ${INSTALL_WRKSRC}/bin/mono/2.0/release && ${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil /root ${STAGEDIR}${PREFIX}/lib/ /gacdir ${STAGEDIR}${PREFIX}/lib /package 2.0 /i log4net.dll)
	${INSTALL_DATA} ${WRKDIR}/log4net.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/log4net.pc

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${ECHO_CMD} "Installing examples..."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
