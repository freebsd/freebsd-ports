# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.6.2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automotive simulation framework

LIB_DEPENDS=	alut.1:${PORTSDIR}/audio/freealut \
		openal.0:${PORTSDIR}/audio/openal \
		png.5:${PORTSDIR}/graphics/png

USE_GL=		glut
USE_SDL=	sdl
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	ac_cv_header_boost_test_unit_test_hpp=no \
		ac_cv_lib_freeglut_glutGetModifiers=no
USE_LDCONFIG=	yes

INFO=		vamos

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-pedantic -O2 -g||g'

.include <bsd.port.mk>
