# New ports collection makefile for:	violetland
# Date created:		25 Oct 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	violetland
PORTVERSION=	0.3.0
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Top-down survival shoot 'em up

USE_ZIP=	yes
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=yes
CMAKE_ARGS=	-DDATA_INSTALL_DIR="${DATADIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}

DESKTOP_ENTRIES="Violetland" \
		"Top-down survival shoot 'em up" \
		"${DATADIR}/icon-light.png" \
		"violetland" \
		"Game;ArcadeGame;" \
		false

.include <bsd.port.mk>
