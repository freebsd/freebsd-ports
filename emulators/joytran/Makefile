# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	joytran
PORTVERSION=	0.9.5.1
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
USE_SDL=	sdl2
USES=		cmake pkgconfig
CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" -DPREFIX="${PREFIX}"
USE_XORG=	x11 xtst

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
