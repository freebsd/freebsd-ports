# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.6.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:S/./,/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automotive simulation framework

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_OPENAL=	al alut
USE_GL=		glut
USE_SDL=	sdl
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
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
