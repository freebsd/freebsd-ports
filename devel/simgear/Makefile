# New ports collection makefile for:	SimGear
# Date created:				2003-01-21
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	SimGear
PORTVERSION=	0.3.5
CATEGORIES=	devel games
MASTER_SITES=	ftp://ftp.simgear.org/pub/simgear/Source/ \
		ftp://ftp.de.flightgear.org/pub/simgear/Source/

MAINTAINER=	des@FreeBSD.org
COMMENT=	A toolkit for 3D games and simulations

# These should be LIB_DEPENDS, but it seems bsd.port.mk can't handle
# versionless or static libraries.
BUILD_DEPENDS=	${LOCALBASE}/lib/libmk4.so:${PORTSDIR}/databases/metakit \
		${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
RUN_DEPENDS=	${LOCALBASE}/lib/libmk4.so:${PORTSDIR}/databases/metakit \
		${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

USE_X_PREFIX=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Internal compiler error in gcc"
.endif

.include <bsd.port.post.mk>
