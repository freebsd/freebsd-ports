# New ports collection makefile for:	SimGear
# Date created:				2003-01-21
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	SimGear
PORTVERSION=	0.3.1
CATEGORIES=	devel games
MASTER_SITES=	ftp://ftp.simgear.org/pub/simgear/Source/ \
		ftp://ftp.de.flightgear.org/pub/simgear/

MAINTAINER=	des@FreeBSD.org

# These should be LIB_DEPENDS, but it seems bsd.port.mk can't handle
# versionless or static libraries.
BUILD_DEPENDS=	${LOCALBASE}/lib/libmk4.so:${PORTSDIR}/databases/metakit \
		${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

USE_X_PREFIX=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
# Force configure to look in /usr/local/{include,lib}
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
