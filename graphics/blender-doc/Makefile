PORTNAME=	blender
DISTVERSION=	4.2
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
VER_SHORT=	${DISTVERSION:S/.//g}
VER=		v${VER_SHORT}0
PLIST_SUB+=	VER=${VER} VER_SHORT=${VER_SHORT}

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} blender_manual_${VER}_en.html \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/blender_manual_${VER}_en.epub/Blender${VER_SHORT}Manual.epub \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
