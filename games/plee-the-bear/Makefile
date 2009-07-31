# New ports collection makefile for:	plee-the-bear
# Date created:		28 Mar 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	plee-the-bear
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-light

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D platform jump and run game

LIB_DEPENDS=	boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		claw_application.1:${PORTSDIR}/devel/libclaw

USE_BZIP2=	yes
USE_SDL=	sdl mixer
USE_GL=		gl glu
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_MODULE_PATH="${LOCALBASE}/lib/claw/"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|"stats.dat"|get_custom_game_file(&).c_str()| ' \
		${WRKSRC}/dev/bear_engine/src/core/engine/code/game.cpp

.include <bsd.port.mk>
