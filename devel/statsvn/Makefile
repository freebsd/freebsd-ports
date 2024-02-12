PORTNAME=	statsvn
PORTVERSION=	0.7.0
PORTREVISION=	6
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subversion repository activity report generator
WWW=		https://www.statsvn.org/

LICENSE=	LGPL21+

.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	subversion-lts>0:devel/subversion-lts
.else
RUN_DEPENDS=	subversion>0:devel/subversion
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	8
USE_ANT=	yes
NO_ARCH=	yes

ALL_TARGET=	dist

SUB_FILES=	statsvn
SUB_LIST=	JAVA=${JAVA}

PORTDOCS=	*
PLIST_FILES=	bin/statsvn \
		%%DATADIR%%/statsvn.jar

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	javadoc

do-install:
	(cd ${WRKSRC}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/statsvn ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
