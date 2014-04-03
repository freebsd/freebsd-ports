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

RUN_DEPENDS=	subversion>=1.3:${PORTSDIR}/devel/subversion

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USES=		zip
USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	1.6+

ALL_TARGET=	dist

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	(cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
