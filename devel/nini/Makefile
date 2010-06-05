# New ports collection makefile for:	nini
# Date created:		2009-04-27
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	nini
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	nini/Nini/${PORTVERSION}
DISTNAME=	Nini-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	NET configuration library

RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Nini

NINI_VERSION=	${PORTVERSION:C/([0-9]*\.[0-9]*).*/\1/}

SUB_FILES=	${PORTNAME}.pc
SUB_LIST+=	PORTVERSION=${PORTVERSION} \
		NINI_VERSION=${NINI_VERSION}

PLIST_SUB+=	NINI_VERSION=${NINI_VERSION}

.if !defined (NOPORTDOCS)
PORTDOCS=	*
.endif
.if !defined (NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

do-install:
	@(cd ${INSTALL_WRKSRC}/Bin/Mono/1.1/Release && ${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil -root ${PREFIX}/lib/ -gacdir ${PREFIX}/lib -package ${PORTNAME}-${NINI_VERSION} -i Nini.dll)
	@${INSTALL_DATA} ${WRKDIR}/nini.pc ${PREFIX}/libdata/pkgconfig/nini-${NINI_VERSION}.pc

.if !defined (NOPORTEXAMPLES)
	@${ECHO_CMD} "Installing examples..."
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/Examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.if !defined (NOPORTDOCS)
	@${ECHO_CMD} "Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/Docs/ && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
