# Created by: trevor
# $FreeBSD$

PORTNAME=	linplasma
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/hacks/svgalib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sinus plasma, an SVGAlib demo

LIB_DEPENDS=	libvga.so:graphics/svgalib

ONLY_FOR_ARCHS=	i386

ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	"@(root,,4755) bin/linplasma"
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s:PI:M_PI:" ${WRKSRC}/linplasma.c
	@${REINPLACE_CMD} -e \
		"s:(int)palptr = (int:palptr = (unsigned char *:" \
			${WRKSRC}/linplasma.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linplasma ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
