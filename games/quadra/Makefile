# New ports collection makefile for:	quadra
# Date created:		2011-12-25
# Whom:			Karsten Brandt <kbrandt@sdf-eu.org>
#
# $FreeBSD$
#

PORTNAME=	quadra
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://kbrandt.sdf-eu.org/FreeBSD/distfiles/ \
		ftp://ftp.bsdforen.de/pub/BSDForen/distfiles/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	kbrandt@sdf-eu.org
COMMENT=	Tetris like game with multiplayer support

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_SDL=	sdl
USE_XORG=	x11 xau xdmcp
USE_AUTOTOOLS=	autoconf autoheader
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/games/${PORTNAME}.res \
		share/pixmaps/${PORTNAME}.xpm
PLIST_DIRSTRY=	share/games

DESKTOP_ENTRIES=	"Quadra" "${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
			"${PORTNAME}" "Application;BlocksGame;Game;" false

# maintainer relevant make target:
SVN_REV=	757
SVN_SRC=	http://quadra.googlecode.com/svn/trunk/quadra/

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export -r${SVN_REV} ${SVN_SRC} ${PORTNAME}-${PORTVERSION}
	${TAR} cjf ${DISTDIR}/${DISTNAME}.tar.bz2 ${PORTNAME}-${PORTVERSION}
	${RM} -rf ${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
