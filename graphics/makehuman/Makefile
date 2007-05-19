# New ports collection makefile for:	makehuman
# Date created:		06 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	makehuman
DISTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Application for parametrical modeling of 3D humanoid characters

LIB_DEPENDS=	animorph.0:${PORTSDIR}/graphics/animorph \
		mhgui.0:${PORTSDIR}/graphics/mhgui \
		glut.4:${PORTSDIR}/graphics/libglut

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GL=		yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|makehuman/|.&|g' ${WRKSRC}/src/util.cpp
	@${REINPLACE_CMD} -e '/^makehuman_pixmapsdir =/ s|pixmaps/makehuman|makehuman/pixmaps|' ${WRKSRC}/pixmaps/Makefile.in
	@${REINPLACE_CMD} -e '/^packagepixmapsdir=/ s|pixmaps/\$${PACKAGE}|$${PACKAGE}/pixmaps|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^makehumandocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-makehumandocDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
