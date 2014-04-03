# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	statcvs
PORTVERSION=	0.7.0
CATEGORIES=	devel java
MASTER_SITES=	SF/${PORTNAME}/Download%20StatCVS/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS repository activity report generator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USES=		zip
USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	1.6+

ALL_TARGET=	jar

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
