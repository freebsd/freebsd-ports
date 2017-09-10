# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	mhgui
PORTVERSION=	0.2
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF/makehuman/MakeHuman%20Source/MakeHuman_091

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GUI widget library for MakeHuman

LICENSE=	GPLv2

LIB_DEPENDS=	libanimorph.so:graphics/animorph \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USES=		pkgconfig gmake libtool
USE_LDCONFIG=	yes
USE_XORG=	xi xmu ice sm
USE_GL=		glut
INSTALL_TARGET=	install-strip
USE_GCC=	any # otherwise graphics/makehuman won't link

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^libmhguidocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|\$$(libdir)|\$$(exec_prefix)/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
