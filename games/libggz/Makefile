# ex:ts=8
# Ports collection makefile for:	libggz
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libggz
PORTVERSION=	0.0.12
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://mirrors.dotsrc.org/ggzgamingzone/ggz/%SUBDIR%/ \
		http://ftp.ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - Base Library

USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug
INSTALLS_SHLIB=	yes

MAN3=	ggz.h.3

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.15:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-tls=GnuTLS
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-tls=OpenSSL
.endif

.include <bsd.port.mk>
