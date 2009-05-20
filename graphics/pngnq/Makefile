# New ports collection makefile for:   pngnq
# Date created:        10 May 2009
# Whom:                stb@lassitu.de
#
# $FreeBSD$
#

PORTNAME=	pngnq
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	stb@lassitu.de
COMMENT=	A tool for quantizing PNG images in RGBA format

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTVERSION}

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include -DVERSION='\"${PORTVERSION}\"'" \
		LDFLAGS="-lpng -lz -lm -L${LOCALBASE}/lib"

PORTDOCS=	README LICENSE README.pngcomp
PLIST_FILES=	bin/pngcomp bin/pngnq
.if !defined(NO_INSTALL_MANPAGES)
MAN1=		pngnq.1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcomp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pngnq ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/pngnq.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>
