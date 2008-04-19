# New ports collection makefile for:	mhgui
# Date created:		31 Mar 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	mhgui
PORTVERSION=	0.2
CATEGORIES=	graphics
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	makehuman

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	GUI widget library for MakeHuman

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut \
		animorph.0:${PORTSDIR}/graphics/animorph \
		png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_GL=		yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^libmhguidocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|\$$(libdir)|\$$(exec_prefix)/libdata|' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-libmhguidocDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
