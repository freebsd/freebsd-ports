# New ports collection makefile for:	statcvs
# Date created:				25 Mar 2009
# Whom:					glarkin
#
# $FreeBSD$
#

PORTNAME=	statcvs
PORTVERSION=	0.5.0
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	CVS repository activity report generator

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_ZIP=	yes
USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	1.4+

.if !defined(NOPORTDOCS)
ALL_TARGET=	jar javadoc
.else
ALL_TARGET=	jar
.endif

SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${DATADIR}
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
