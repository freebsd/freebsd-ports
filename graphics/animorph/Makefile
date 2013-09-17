# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	animorph
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	SF/makehuman/MakeHuman%20Source/MakeHuman_091

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Morphing engine for MakeHuman

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		pkgconfig
USE_LDCONFIG=	yes
USE_GCC=	yes # otherwise graphics/makehuman won't link

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^libanimorphdocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|\$$(libdir)|\$$(exec_prefix)/libdata|' ${WRKSRC}/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-libanimorphdocDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
