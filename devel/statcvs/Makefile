# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	statcvs
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	SF/${PORTNAME}/Download%20StatCVS/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS repository activity report generator

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/etc/LICENSE

BROKEN_armv6=		fails to compile: build.xml: compilation failed
BROKEN_armv7=		fails to compile: build.xml: compilation failed

USES=		zip
USE_JAVA=	yes
USE_ANT=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

ALL_TARGET=	jar

SUB_FILES=	pkg-message

PORTDOCS=	*
PLIST_FILES=	%%DATADIR%%/statcvs.jar

OPTIONS_DEFINE=	DOCS
DOCS_ALL_TARGET=javadoc

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION:M*6*}
PLIST_SUB+=	JDK6=""
.else
PLIST_SUB+=	JDK6="@comment "
.endif

do-install:
	(cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
