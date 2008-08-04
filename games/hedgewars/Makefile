# New ports collection makefile for:	hedgewars
# Date created:		24 May 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hedgewars
PORTVERSION=	0.9.6
CATEGORIES=	games
MASTER_SITES=	http://hedgewars.org/download/ \
		http://www.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Worms-like turn based strategy game

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_SDL=	sdl mixer image ttf net
USE_FPC=	opengl
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build network qmake_build rcc_build svg xml

post-patch:
	${ECHO} "include_directories(${LOCALBASE}/include)" >> \
		${WRKSRC}/QTfrontend/CMakeLists.txt

.include <bsd.port.mk>
