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

LIB_DEPENDS=	animorph:${PORTSDIR}/graphics/animorph \
		png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		pkgconfig
USE_LDCONFIG=	yes
USE_XORG=	xi xmu ice sm
USE_GL=		glut

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^libmhguidocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|\$$(libdir)|\$$(exec_prefix)/libdata|' ${WRKSRC}/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-libmhguidocDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
