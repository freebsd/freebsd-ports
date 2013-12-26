# Created by: glarkin
# $FreeBSD$

PORTNAME=	statsvn
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subversion repository activity report generator

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper \
		subversion>=1.3:${PORTSDIR}/devel/subversion

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_ZIP=	yes
USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	1.6+

.if !defined(NOPORTDOCS)
ALL_TARGET=	dist javadoc
.else
ALL_TARGET=	dist
.endif

SUB_FILES=	pkg-message

NO_STAGE=	yes
do-install:
	@cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${DATADIR}
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
