# New ports collection makefile for:	stellarium
# Date created:			26 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	stellarium
PORTVERSION=	0.8.0
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A 3D photo-realistic sky renderer

BUILD_DEPENDS=	icoconvert:${PORTSDIR}/graphics/icoconvert
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

USE_GCC=	3.3+
USE_GETTEXT=	yes
USE_GL=		yes
USE_SDL=	sdl mixer
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		stellarium.1
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

DESKTOP_ENTRIES="Stellarium" \
		"View the sky" \
		"stellarium.png" \
		"stellarium" \
		"Application;Astronomy;Science;Education;" \
		false

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

post-build:
	@icoconvert ${WRKSRC}/data/stellarium.ico

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/stellarium_64X64_32bpp.png \
		${PREFIX}/share/pixmaps/stellarium.png
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
