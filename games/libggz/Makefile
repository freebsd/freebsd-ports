# ex:ts=8
# Ports collection makefile for:	libggz
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libggz
PORTVERSION=	0.0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Base Library

LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--disable-debug --with-gcrypt --with-tls

INSTALLS_SHLIB=	yes

MAN3=	ggz.h.3

.include <bsd.port.mk>
