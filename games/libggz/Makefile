# ex:ts=8
# Ports collection makefile for:	libggz
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libggz
PORTVERSION=	0.0.8
CATEGORIES=	games
MASTER_SITES=	http://ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Base Library

LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt

USE_GNOME=	gnomehack gnometarget
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug --with-gcrypt --with-tls
INSTALLS_SHLIB=	yes

MAN3=	ggz.h.3

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
