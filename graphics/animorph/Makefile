# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	animorph
PORTVERSION=	0.3
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/makehuman/MakeHuman%20Source/MakeHuman_091

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Morphing engine for MakeHuman

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USES=		pkgconfig gmake libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
USE_GCC=	any # otherwise graphics/makehuman won't link
USE_CXXSTD=	gnu++98  # The port is not compatible with C++11 and later.

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^libanimorphdocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|\$$(libdir)|\$$(exec_prefix)/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
