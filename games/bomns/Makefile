# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	bomns
PORTVERSION=	0.99.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/greenridge/Bomns%20for%20Linux/Bomns%20for%20Linux%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Best old-school Deathmatch game ever (only for two players)

USES=		pkgconfig
USE_BZIP2=	yes
USE_SDL=	mixer sdl
WANT_GNOME=	yes
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CPPFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS+=	`${SDL_CONFIG} --libs`
CONFIGURE_ARGS=	--program-transform-name=

OPTIONS_DEFINE=	EDITOR LAUNCHER OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	EDITOR LAUNCHER OPTIMIZED_CFLAGS
EDITOR_DESC=	Enable building of the map editor
LAUNCHER_DESC=	Enable building of the GTK2 launcher

OPTIONS_SUB=	yes

EDITOR_CONFIGURE_ENABLE=	editor

LAUNCHER_USE=	GNOME=gtk20
LAUNCHER_CONFIGURE_ENABLE=	launcher2

.include <bsd.port.options.mk>

post-patch:
# Fix SDL include statement.
.for f in *.cpp *.h
	@${FIND} ${WRKSRC}/src -type f -name ${f} -print0 | \
		${XARGS} -0 \
		${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2|'
.endfor

# Remove -lSDL linker flag.
.for f in Makefile.am Makefile.in
	@${FIND} ${WRKSRC}/src -type f -name ${f} -print0 | \
		${XARGS} -0 \
		${REINPLACE_CMD} -e 's|-lSDL || ; s|-lSDL$$|| ; s|-lpthread||'
.endfor

# Enable/disable compilation optimizations.
.if empty(PORT_OPTIONS:MOPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O2||' ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.include <bsd.port.mk>
