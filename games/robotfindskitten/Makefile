# Ports collection makefile for:  robotfindskitten
# Date created:                   Wed Dec 3, 2003
# Whom:                           Ceri Davies (ceri@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	robotfindskitten
PORTVERSION=	1600003.248b
CATEGORIES=	games
MASTER_SITES=	http://robotfindskitten.org/download/POSIX/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ceri@FreeBSD.org
COMMENT=	Yet another zen simulation

GNU_CONFIGURE=	YES
USE_GNOME=	glib12

INFO=		${PORTNAME}
PLIST_FILES=	bin/robotfindskitten

post-extract:
	${RM}	${WRKSRC}/doc/robotfindskitten.info

.include <bsd.port.mk>
