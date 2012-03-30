# New ports collection makefile for:	joytran
# Date created:			30 Jul 2011
# Whom:				Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	joytran
PORTVERSION=	0.8.7
CATEGORIES=	emulators
MASTER_SITES=	BERLIOS GOOGLE_CODE
MASTER_SITE_SUBDIR=	joytran

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Joystick to keyboard/mouse events translator written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

# This is needed to fetch from BerliOS
FETCH_ARGS=	"-Fpr"
USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" -DPREFIX="${PREFIX}"

.if !defined(NOPORTDOCS)
CMAKE_ARGS+=	-DINSTALL_DOCUMENTATION:BOOL=ON
.else
CMAKE_ARGS+=	-DINSTALL_DOCUMENTATION:BOOL=OFF
.endif

USE_SDL=	sdl
USE_XORG=	x11 xtst

.include <bsd.port.mk>
