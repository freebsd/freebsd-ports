# Ports collection makefile for:  robotfindskitten
# Date created:                   Wed Dec 3, 2003
# Whom:                           Ceri Davies (ceri@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	robotfindskitten
PORTVERSION=	1.7320508.406
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	http://robotfindskitten.org/download/POSIX/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	skreuzer@exit2shell.com
COMMENT=	Yet another zen simulation

GNU_CONFIGURE=	YES
USE_GNOME=	glib12
CONFIGURE_TARGET= --build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

INFO=		${PORTNAME}
PLIST_FILES=	bin/robotfindskitten

post-extract:
	${RM}	${WRKSRC}/doc/robotfindskitten.info

.include <bsd.port.mk>
