# New ports collection makefile for:	pngcheck
# Date created:				Tue 04 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	pngcheck
PORTVERSION=	2.3.0
CATEGORIES=	graphics
MASTER_SITES=	SF/png-mng/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checks the integrity of PNG images

MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS} -DUSE_ZLIB" LIBS="-lz"

PORTDOCS=	CHANGELOG README
PLIST_FILES=	bin/pngcheck

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcheck ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
