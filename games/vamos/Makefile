# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automotive simulation framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_OPENAL=	al alut
USE_XORG=	sm ice x11 xi xext xmu
USE_GL=		glut
USE_SDL=	sdl
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	ac_cv_header_boost_test_unit_test_hpp=no \
		ac_cv_lib_freeglut_glutGetModifiers=no
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

INFO=		vamos

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/config/install-sh

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^AM_CXXFLAGS/s| -pedantic|| ; \
		 /^AM_CXXFLAGS/s| -O[[:alnum:]]|| ; \
		 /^AM_CXXFLAGS/s| -g|| ; \
		 /^AM_CXXFLAGS/s| -DBOOST_TEST_DYN_LINK|| ; \
		 /^AM_CXXFLAGS/s| -L/usr/lib/boost||'

.include <bsd.port.mk>
