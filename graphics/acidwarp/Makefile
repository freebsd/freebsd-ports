# Created by: trevor
# $FreeBSD$

PORTNAME=	acidwarp
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/hacks/svgalib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SVGAlib demo which displays trippy mathematical images in cycling colors

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

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
	${INSTALL_PROGRAM} ${WRKSRC}/acidwarp ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
