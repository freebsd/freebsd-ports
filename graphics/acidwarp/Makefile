# New ports collection makefile for:	acidwarp
# Date created:				2000-10-22
# Whom:					trevor
#
# $FreeBSD$
#

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

OPTION=		SETUID "Install with setuid bit set" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SETUID)
BINMODE=	4555
.endif

post-extract:
	${RM} -f ${WRKSRC}/acidwarp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acidwarp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
