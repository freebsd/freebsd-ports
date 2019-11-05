# Created by: Karsten Brandt <kbrandt@sdf-eu.org>
# $FreeBSD$

PORTNAME=	quadra
PORTVERSION=	1.3.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://kbrandt.sdf-eu.org/FreeBSD/distfiles/ \
		ftp://ftp.bsdforen.de/pub/BSDForen/distfiles/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	kbrandt@sdf-eu.org
COMMENT=	Tetris like game with multiplayer support

LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf gmake localbase sdl tar:bzip2 xorg
USE_SDL=	sdl
USE_XORG=	x11 xau xdmcp
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/games/${PORTNAME}.res \
		share/pixmaps/${PORTNAME}.xpm

DESKTOP_ENTRIES=	"Quadra" "${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
			"${PORTNAME}" "BlocksGame;Game;" false

# maintainer relevant make target:
# Note that googlecode.com is gone.
SVN_REV=	757
SVN_SRC=	http://quadra.googlecode.com/svn/trunk/quadra/

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export -r${SVN_REV} ${SVN_SRC} ${PORTNAME}-${PORTVERSION}
	${TAR} cjf ${DISTDIR}/${DISTNAME}.tar.bz2 ${PORTNAME}-${PORTVERSION}
	${RM} -r ${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
