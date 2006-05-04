# New ports collection makefile for:	gauche
# Date created:		9 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gauche-sdl
PORTVERSION=	0.5.1
CATEGORIES=	devel scheme
MASTER_SITES=	http://www.michaelvess.com/code/
DISTNAME=	${PORTFAKENAME}-${PORTVERSION}

MAINTAINER=	erik@smluc.org
COMMENT=	Scheme script interpreter with multibyte character handling

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche \
		${X11BASE}/lib/X11/rgb.txt:${X_CLIENTS_PORT}
RUN_DEPENDS=	gosh:${PORTSDIR}/lang/gauche \
		${X11BASE}/lib/X11/rgb.txt:${X_CLIENTS_PORT}

PLIST_SUB=	GAUCHE_VERSION="`gauche-config -V`"\
		TARGET="${CONFIGURE_TARGET}"
WRKSRC=		${WRKDIR}/${PORTFAKENAME}
PORTFAKENAME=	Gauche-sdl
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes

pre-configure:
.for DIR in . image mixer ttf
		${REINPLACE_CMD} \
			-e "s|^CFLAGS .*|& `${SDL_CONFIG} --cflags`|"\
			-e "s|-lSDL|`${SDL_CONFIG} --libs`|"\
			${WRKSRC}/src/${DIR}/Makefile.in
.endfor
		${REINPLACE_CMD} \
			-e "s|SDL/SDL|SDL|g"\
			-e "s|%%SDL_CFLAGS%%|`${SDL_CONFIG} --cflags`|"\
			${WRKSRC}/configure
		${REINPLACE_CMD} -e "s|^CFLAGS.*|& `${SDL_CONFIG} --cflags`|" \
			${WRKSRC}/src/gfx/Makefile.in

.include <bsd.port.mk>
