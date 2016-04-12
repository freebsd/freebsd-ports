# Created by: trevor
# $FreeBSD$

PORTNAME=	acidwarp
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/hacks/svgalib

MAINTAINER=	swills@FreeBSD.org
COMMENT=	SVGAlib demo which displays trippy mathematical images in cycling colors

LIB_DEPENDS=	libvga.so:graphics/svgalib

ONLY_FOR_ARCHS=	i386
ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/acidwarp
PORTDOCS=	README TODO Thanks

OPTIONS_DEFINE=	SETUID DOCS
OPTIONS_DEFAULT=	SETUID
SETUID_DESC=	Install with setuid bit set

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSETUID}
BINMODE=	4555
.endif

post-extract:
	${RM} -f ${WRKSRC}/acidwarp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acidwarp ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
