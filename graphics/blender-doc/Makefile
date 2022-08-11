PORTNAME=	blender
PORTVERSION=	2.3
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/documentation/
PKGNAMESUFFIX=	-doc
DISTFILES=	BlenderManualIen.23.html.tar.gz BlenderManualIIen.23.html.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blender Documentation

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

pre-patch:
	@cd ${WRKSRC}/htmlI/PartAT/volumetrics/gfx/ && \
		${RM} -r  "Nuova cartella" "Nuova cartella (2)"

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "htmlI htmlII" ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
