# Created by: trevor
# $FreeBSD$

PORTNAME=	linplasma
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/hacks/svgalib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sinus plasma, an SVGAlib demo

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

ONLY_FOR_ARCHS=	i386

ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/linplasma
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e "s:PI:M_PI:" ${WRKSRC}/linplasma.c
	@${REINPLACE_CMD} -e \
		"s:(int)palptr = (int:palptr = (unsigned char *:" \
			${WRKSRC}/linplasma.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linplasma ${PREFIX}/bin
	${CHMOD} +s ${PREFIX}/bin/linplasma
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
