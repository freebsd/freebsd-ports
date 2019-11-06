# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	mhgui
PORTVERSION=	0.2
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	SF/makehuman/MakeHuman%20Source/MakeHuman_091

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI widget library for MakeHuman

BROKEN=		unfetchable

LICENSE=	GPLv2

LIB_DEPENDS=	libanimorph.so:graphics/animorph \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USES=		pkgconfig gl gmake libtool xorg
USE_LDCONFIG=	yes
USE_XORG=	xi xmu ice sm
USE_GL=		glut
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^libmhguidocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|\$$(libdir)|\$$(exec_prefix)/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
