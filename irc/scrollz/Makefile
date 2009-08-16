# New ports collection makefile for:	ScrollZ
# Date created:		10 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	scrollz
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	http://scrollz.lysergide.net/ScrollZ/source/ \
		http://mirror.inf.udec.cl/ftp.scrollz.com/ScrollZ/source/
DISTNAME=	ScrollZ-${PORTVERSION}

MAINTAINER=	mdv@unsavoury.net
COMMENT=	Enhanced ircII client that supports scripts, colors, and more

USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ipv6 --enable-regexp

MAKE_ENV+=	IRCLIB="${PREFIX}/share/scrollz"

PLIST_SUB+=	SCROLLZ_VER="${PORTVERSION}"

MAN1=	scrollz.1

.if defined(WITH_SSL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libgnutls.a:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl
.endif

pre-build:
.if !defined(BATCH)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o SZdist SZdist.c)
	@(cd ${WRKSRC}; ./SZdist)
.endif

.include <bsd.port.mk>
