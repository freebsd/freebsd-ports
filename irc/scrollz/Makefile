# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	scrollz
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.netraam.net/scrollz/download/ \
		http://www.scrollz.com/download/
DISTNAME=	ScrollZ-${PORTVERSION}

MAINTAINER=	mdv@unsavoury.net
COMMENT=	Enhanced ircII client that supports scripts, colors, and more

USES=		gmake iconv ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --enable-regexp --enable-iconv
MAKE_ENV=	IRCLIB="${PREFIX}/share/scrollz"

MAN1=		scrollz.1
PORTDATA=	*

PLIST_SUB+=	SCROLLZ_VER="${PORTVERSION}"

OPTIONS_DEFAULT=	OPENSSL
OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

pre-build:
.if !defined(BATCH)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o SZdist SZdist.c)
	@(cd ${WRKSRC}; ./SZdist)
.endif

.include <bsd.port.mk>
