# New ports collection makefile for:	gltron
# Date created:				24 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gltron
PORTVERSION=	0.62
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://gltron.sourceforge.net/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D worm game for two players for X Window System

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod \
		SDL_sound-1.0.1:${PORTSDIR}/audio/sdl_sound \
		SDL_net.0:${PORTSDIR}/net/sdl_net \
		png.5:${PORTSDIR}/graphics/png

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		SDL_CONFIG="${SDL_CONFIG}"

MAN6=		gltron.6

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O2|@CFLAGS@|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
