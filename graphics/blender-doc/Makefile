PORTNAME=	blender
PORTVERSION=	3.5
CATEGORIES=	graphics
MASTER_SITES=	https://docs.blender.org/manual/en/${PORTVERSION}/
PKGNAMESUFFIX=	-doc
DISTFILES=	blender_manual_html.zip blender_manual_epub.zip
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blender Documentation
WWW=		https://docs.blender.org/

USES=		zip

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes
VER=		v350

SUB_FILES=	pkg-message
PLIST_SUB+=	VER=${VER}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTNAME}*" ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
