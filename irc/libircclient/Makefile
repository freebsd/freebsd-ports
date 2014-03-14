# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	libircclient
PORTVERSION=	1.7
CATEGORIES=	irc devel
MASTER_SITES=	SF

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	An IRC library to create IRC clients

LICENSE=	LGPL20

OPTIONS_DEFINE=	OPENSSL IPV6 EXAMPLES
OPTIONS_DEFAULT=	OPENSSL

BUILD_WRKSRC=	${WRKSRC}/src
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--enable-openssl
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

do-install:
	@${INSTALL_DATA} ${WRKSRC}/include/libircclient.h ${STAGEDIR}${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_errors.h ${STAGEDIR}${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_events.h ${STAGEDIR}${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_options.h ${STAGEDIR}${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_rfcnumeric.h ${STAGEDIR}${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/src/libircclient.a ${STAGEDIR}${PREFIX}/lib

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
