# Ports collection makefile for:  robotfindskitten
# Date created:                   Wed Dec 3, 2003
# Whom:                           Ceri Davies (ceri@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	robotfindskitten
PORTVERSION=	1.7320508.406
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	http://robotfindskitten.org/download/POSIX/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Yet another zen simulation

GNU_CONFIGURE=	YES
USE_GNOME=	glib12

INFO=		${PORTNAME}
PLIST_FILES=	bin/robotfindskitten
MAN6=		robotfindskitten.6

post-extract:
	${RM}	${WRKSRC}/doc/robotfindskitten.info

.include <bsd.port.mk>
