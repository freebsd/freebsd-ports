# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autopano-sift-C
PORTVERSION=	2.5.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/hugin/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Automatic panorama control point generation tool, C port

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png \
		libpano13.so:${PORTSDIR}/graphics/libpano13

RESTRICTED=	May be covered by patents

CONFLICTS=	autopano-sift-[0-9]*

USE_GNOME=	libxml2
USES=		cmake

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1ST ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
