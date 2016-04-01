# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	ScrollZ
PORTVERSION=	2.3
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=	irc ipv6

MAINTAINER=	freebsd@bitchx.org
COMMENT=	Enhanced ircII client that supports scripts, colors, and more

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gmake iconv ncurses
USE_GITHUB=	yes
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
PLIST_SUB=	SCROLLZ_VER="${PORTVERSION}"

OPTIONS_DEFINE=		IPV6 REGEX UTF8
OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL REGEX UTF8

IPV_CONFIGURE_ENABLE=	ipv6
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
GNUTLS_CONFIGURE_ON=	--with-ssl
REGEX_CONFIGURE_ENABLE=	regexp
OPENSSL_USE=		OPENSSL=yes
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
UTF8_CONFIGURE_ENABLE=	utf8

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
