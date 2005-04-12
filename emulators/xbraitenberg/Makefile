# New ports collection makefile for:  	xbraitenberg
# Date created:       		28 Mar 2004
# Whom:  			krion
#
# $FreeBSD$
#

PORTNAME=	xbraitenberg
PORTVERSION=	0.8
CATEGORIES=	emulators
MASTER_SITES=	http://www.lcdf.org/~eddietwo/xbraitenberg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Braitenberg vehicle simulator with pseudo-physics

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"

PLIST_FILES=	bin/xbraitenberg

.include <bsd.port.mk>
