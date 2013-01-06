# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	libircclient
PORTVERSION=	1.6
CATEGORIES=	irc devel
MASTER_SITES=	SF

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	An IRC library to create IRC clients

OPTIONS_DEFINE=	OPENSSL IPV6 DOCS EXAMPLES
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
	@${INSTALL_DATA} ${WRKSRC}/include/libircclient.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_errors.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_events.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_options.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/libirc_rfcnumeric.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/src/libircclient.a ${PREFIX}/lib

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "installing additional examples to ${EXAMPLESDIR}"
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
