# ex:ts=8
# Ports collection makefile for:	csmash
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	csmash
PORTVERSION=	0.6.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cannonsmash

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D tabletennis game

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext

USE_REINPLACE=	yes
USE_SDL=	yes
USE_GL=		yes
USE_GNOME=	gtk12 gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
MAKEFILE=	makefile

post-patch:
	@${GREP} -lR "SDL/" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s@SDL/@SDL11/@g"
	@${FIND} ${WRKSRC} -name "makefile.in" | ${XARGS} \
		${GREP} -lR "games/" | ${XARGS} ${REINPLACE_CMD} \
		-e "s@games/@@g"

.include <bsd.port.mk>
