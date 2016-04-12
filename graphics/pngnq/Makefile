# Created by: stb@lassitu.de
# $FreeBSD$

PORTNAME=	pngnq
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	stb@lassitu.de
COMMENT=	Tool for quantizing PNG images in RGBA format

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpng.so:graphics/png

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lpng

USES=		pkgconfig

PORTDOCS=	README COPYING
PLIST_FILES=	bin/pngcomp bin/pngnq man/man1/pngnq.1.gz

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}/${DOCSDIR}
.endfor

.include <bsd.port.mk>
