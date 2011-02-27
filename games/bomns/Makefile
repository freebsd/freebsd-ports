# New ports collection makefile for:	bomns
# Date created:				22 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	bomns
PORTVERSION=	0.99.2
CATEGORIES=	games
MASTER_SITES=	SF/greenridge/Bomns%20for%20Linux/Bomns%20for%20Linux%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The best old-school deathmatch game EVER (only for two players)

USE_BZIP2=	yes
USE_SDL=	mixer sdl
WANT_GNOME=	yes
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LDFLAGS="`${SDL_CONFIG} --libs`"
CONFIGURE_ARGS=	--program-transform-name=

OPTIONS=	EDITOR "Enable building of the map editor" on \
		LAUNCHER "Enable building of the GTK2 launcher" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EDITOR)
PLIST_SUB+=	EDITOR=""
.else
CONFIGURE_ARGS+=--disable-editor
PLIST_SUB+=	EDITOR="@comment "
.endif

.if !defined(WITHOUT_LAUNCHER)
USE_GNOME=	gtk20
PLIST_SUB+=	LAUNCHER=""
.else
CONFIGURE_ARGS+=--disable-launcher2
PLIST_SUB+=	LAUNCHER="@comment "
.endif

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
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O2||' ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.include <bsd.port.post.mk>
