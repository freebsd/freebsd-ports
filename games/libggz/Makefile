# ex:ts=8
# Ports collection makefile for:	libggz
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libggz
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	6
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Base Library

LIB_DEPENDS=	gcrypt.16:${PORTSDIR}/security/libgcrypt

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug
USE_LDCONFIG=	yes

MAN3=	ggz.h.3

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-tls=GnuTLS
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-tls=OpenSSL
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/libggz/bsd.ggz.mk"
.include <bsd.port.post.mk>
