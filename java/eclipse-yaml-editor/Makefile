PORTNAME=	eclipse-yaml-editor
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	java devel

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	Eclipse plugin for YAML editing
WWW=		https://github.com/de-jcup/eclipse-yaml-editor/wiki

LICENSE=	APACHE20

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

USE_GITHUB=	YES
GH_TUPLE=	de-jcup:update-site-${PORTNAME}:99ea8dc

NO_ARCH=	YES
NO_BUILD=	YES

PLUGINDIR=	share/eclipse/dropins/${PORTNAME}/eclipse

PLIST_SUB=	PORTVERSION=${PORTVERSION}

do-install:
	@(cd ${WRKSRC}/update-site/ && \
	    ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/${PLUGINDIR})
	@(${FIND} ${STAGEDIR}${PREFIX}/${PLUGINDIR} -type f \
	    ! -name "*${PORTVERSION}*" -delete)

.include <bsd.port.mk>
