# Created by: stb@lassitu.de
# $FreeBSD$

PORTNAME=	pngnq
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	stb@lassitu.de
COMMENT=	A tool for quantizing PNG images in RGBA format

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lpng

USES=		pkgconfig

PORTDOCS=	README COPYING
PLIST_FILES=	bin/pngcomp bin/pngnq man/man1/pngnq.1.gz

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}/${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
