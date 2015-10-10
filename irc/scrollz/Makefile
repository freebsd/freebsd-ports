# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	scrollz
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.netraam.net/scrollz/download/ \
		http://www.scrollz.org/download/
DISTNAME=	ScrollZ-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced ircII client that supports scripts, colors, and more

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gmake iconv ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --enable-regexp --enable-utf8

PLIST_SUB=	SCROLLZ_VER="${PORTVERSION}"

OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_USES=		pkgconfig
GNUTLS_CONFIGURE_ON=	--with-ssl
OPENSSL_USE=		OPENSSL=yes
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}

.include <bsd.port.pre.mk>

.if !empty(ICONV_LIB)
CONFIGURE_ENV+=ac_cv_func_iconv_open=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

pre-build:
.if !defined(BATCH)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o SZdist \
		SZdist.c)
	@(cd ${WRKSRC} && ./SZdist)
.endif

post-install:
.for i in scrollz-${PORTVERSION} wservz
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.post.mk>
