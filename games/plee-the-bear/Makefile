# New ports collection makefile for:	plee-the-bear
# Date created:		28 Mar 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	plee-the-bear
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Plee%20the%20Bear/${PORTVERSION:R}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D platform jump and run game

LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost-libs \
		claw_application:${PORTSDIR}/devel/libclaw

USE_SDL=	sdl mixer
USE_GL=		gl glu
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes
USE_GCC=	4.6+

USE_CMAKE=	yes
CMAKE_ARGS=	-Dlibclaw_DIR="${LOCALBASE}/share/libclaw/cmake" \
		-DBEAR_NO_EDITOR=YES

.include <bsd.port.mk>
