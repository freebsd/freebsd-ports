# Created by: Sheldon Hearn <sheldonh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdoclet
PORTVERSION=	1.2.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}
DISTFILES=	${DISTNAME}.zip xjavadoc-${XJAVADOC_VER}.zip

MAINTAINER=	lxv@omut.org
COMMENT=	Java attribute-oriented code generation engine

BROKEN=		unfetchable

RUN_DEPENDS=	${LOCALBASE}/bin/ant:devel/apache-ant

USES=		zip
USE_JAVA=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

XJAVADOC_VER=	1.1

PLIST_SUB+=	XJAVADOC_VER="${XJAVADOC_VER}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/xdoclet-${PORTVERSION}/lib/*xdoclet* ${STAGEDIR}${JAVAJARDIR}
	cd ${WRKSRC}/xdoclet-${PORTVERSION}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} \
	    ${WRKSRC}/xjavadoc-${XJAVADOC_VER}/xjavadoc-${XJAVADOC_VER}.jar \
	    ${STAGEDIR}${JAVAJARDIR}
	cd ${WRKSRC}/xdoclet-${PORTVERSION}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -empty"

.include <bsd.port.mk>
