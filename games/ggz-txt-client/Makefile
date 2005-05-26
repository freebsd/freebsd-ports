# ex:ts=8
# Ports collection makefile for:	ggz-txt-client
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ggz-txt-client
PORTVERSION=	0.0.11
CATEGORIES=	games
MASTER_SITES=	http://ftp.ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Console (Text) Frontend

LIB_DEPENDS=	ggzcore.7:${PORTSDIR}/games/ggz-client-libs

USE_GNOME=	gnometarget
USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug

MAN6=	ggz-txt.6

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
