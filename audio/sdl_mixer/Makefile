# New ports collection makefile for:	sdl_mixer
# Date created:				24 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sample multi-channel audio mixer library

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_SDL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
INSTALLS_SHLIB=	yes

post-configure:
	@${REINPLACE_CMD} -e \
		's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
			${WRKSRC}/libtool

.include <bsd.port.mk>
