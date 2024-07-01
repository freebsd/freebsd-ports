PORTNAME=	blender
DISTVERSION=	4.1
CATEGORIES=	graphics
MASTER_SITES=	https://docs.blender.org/manual/en/${PORTVERSION}/
PKGNAMESUFFIX=	-doc
DISTFILES=	blender_manual_html.zip blender_manual_epub.zip
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Blender Documentation
WWW=		https://docs.blender.org/

LICENSE=	CC-BY-SA-4.0

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
NO_WRKSUBDIR=	yes
PLIST_SUB+=	VER=v410

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTNAME}*.html" ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC} && ${CP} "${PORTNAME}"*.epub/*.epub      ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
