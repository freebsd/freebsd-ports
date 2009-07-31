# New ports collection makefile for:	gauche
# Date created:		9 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gauche-sdl
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	devel scheme
MASTER_SITES=	http://michaelvess.com/files/
DISTNAME=	${PORTFAKENAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org
COMMENT=	Scheme script interpreter with multibyte character handling

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche \
		${LOCALBASE}/lib/X11/rgb.txt:${PORTSDIR}/x11/rgb
RUN_DEPENDS=	gosh:${PORTSDIR}/lang/gauche \
		${LOCALBASE}/lib/X11/rgb.txt:${PORTSDIR}/x11/rgb

PLIST_SUB=	GAUCHE_VERSION="`gauche-config -V`"\
		TARGET="${CONFIGURE_TARGET}"
PORTFAKENAME=	Gauche-sdl-${PORTVERSION}
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC

pre-configure:
.for DIR in . image mixer ttf
		${REINPLACE_CMD} \
			-e "s|^CFLAGS .*|& `${SDL_CONFIG} --cflags`|"\
			-e "s|-lSDL|`${SDL_CONFIG} --libs`|"\
			${WRKSRC}/src/${DIR}/Makefile.in
.endfor
.for FILE in gfx/gauche-sdl-gfx.h image/gauche-sdl-image.h \
	mixer/gauche-sdl-mixer.h ttf/gauche-sdl-ttf.h gauche-sdl.h
	${REINPLACE_CMD} -e "s|SDL/SDL|SDL|g" ${WRKSRC}/src/${FILE}
.endfor
		${REINPLACE_CMD} \
			-e "s|SDL/SDL|SDL|g"\
			-e "s|%%SDL_CFLAGS%%|`${SDL_CONFIG} --cflags`|"\
			-e "s|\"-lSDL\"|\"`${SDL_CONFIG} --libs`\"|" \
			${WRKSRC}/configure
		${REINPLACE_CMD} -e "s|^CFLAGS.*|& `${SDL_CONFIG} --cflags`|" \
			${WRKSRC}/src/gfx/Makefile.in

.include <bsd.port.mk>
