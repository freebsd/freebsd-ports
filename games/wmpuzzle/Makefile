# New ports collection makefile for:	wmpuzzle
# Date created:			15 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmpuzzle
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://www.godisch.de/debian/wmpuzzle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable puzzle game for WindowMaker and AfterStep

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		wmpuzzle.6
PLIST_FILES=	bin/wmpuzzle

CPPFLAGS=	-I${X11BASE}/include -DBSD
LDFLAGS=	-L${X11BASE}/lib

.include <bsd.port.mk>
