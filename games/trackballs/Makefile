# New ports collection makefile for:	trackballs
# Date created:				21 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trackballs
PORTVERSION=	0.9.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone

LIB_DEPENDS=	SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		guile.15:${PORTSDIR}/lang/guile
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_X_PREFIX=	yes
USE_SDL=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN6=		${PORTNAME}.6

post-patch:
	@${FIND} ${WRKSRC} -name '*.h' -o -name '*.cc' | ${XARGS} \
		${REINPLACE_CMD} -e "/^#include/s|SDL/SDL|SDL11/SDL|; \
			/stdint.h/d"
	@${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
		${WRKSRC}/share/icons/installIcons
	@${REINPLACE_CMD} -e "s|install -D|install|" \
		${WRKSRC}/share/Makefile.in

.include <bsd.port.mk>
