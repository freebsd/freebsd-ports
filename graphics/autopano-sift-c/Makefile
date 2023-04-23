PORTNAME=	autopano-sift-C
PORTVERSION=	2.5.1
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF/hugin/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Automatic panorama control point generation tool, C port
WWW=		http://hugin.sourceforge.net/docs/manual/Autopano-sift-C.html

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libpano13.so:graphics/libpano13

CONFLICTS=	autopano-sift

USE_GNOME=	libxml2
USES=		cmake gnome jpeg

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/set(all_libs/s/$$/ m/' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1ST ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
