# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automotive simulation framework

LIB_DEPENDS=	alut.1:${PORTSDIR}/audio/freealut \
		openal.0:${PORTSDIR}/audio/openal \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnometarget
USE_GL=		glut
USE_SDL=	sdl
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib \
		ac_cv_header_boost_test_unit_test_hpp=no
USE_LDCONFIG=	yes

INFO=		vamos

CPPFLAGS+=	`pkg-config --cflags-only-I sdl freealut libpng12` \
		${PTHREAD_CFLAGS}
LDFLAGS=	`pkg-config --libs-only-L sdl freealut libpng12` \
		${PTHREAD_LIBS}

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-pedantic -O2 -g||g ; \
		 s|libpng`|libpng12`|g'
	@${REINPLACE_CMD} -e 's|freeglut|glut|g ; \
		 s|FREEGLUT|GLUT|g' ${WRKSRC}/configure

.include <bsd.port.mk>
