# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	mhgui
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/makehuman/MakeHuman%20Source/MakeHuman_091

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GUI widget library for MakeHuman

LICENSE=	GPLv2

LIB_DEPENDS=	libanimorph.so:${PORTSDIR}/graphics/animorph \
		libpng15.so:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USES=		pkgconfig gmake
USE_LDCONFIG=	yes
USE_XORG=	xi xmu ice sm
USE_GL=		glut
USE_GCC=	any # otherwise graphics/makehuman won't link

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^libmhguidocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|\$$(libdir)|\$$(exec_prefix)/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
