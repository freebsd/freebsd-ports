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
MASTER_SITES=	http://www.libpng.org/pub/png/src/ \
		ftp://ftp.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/applications/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-lpng -lz -lm -L${LOCALBASE}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngquant ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
