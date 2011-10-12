# New ports collection makefile for:	joytran
# Date created:			30 Jul 2011
# Whom:				Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	joytran
PORTVERSION=	0.8.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Joystick to keyboard/mouse events translator written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}"
USE_SDL=	sdl
USE_XORG=	x11 xtst

PLIST_FILES=	bin/joytran

.include <bsd.port.mk>
