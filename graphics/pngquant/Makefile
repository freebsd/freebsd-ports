# New ports collection makefile for:	pngcquant
# Date created:				Fri 08 Feb 2002
# Whom:					Alex Hayward <xelah@xelah.com>
#
# $FreeBSD$
#

PORTNAME=	pngquant
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/png-mng/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts 32-bit RGBA PNGs into 8-bit RGBA-palette PNGs

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-lpng -lz -lm -L${LOCALBASE}/lib"

PORTDOCS=	CHANGELOG README
PLIST_FILES=	bin/pngquant

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngquant ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
