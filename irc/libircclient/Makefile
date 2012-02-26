# New ports collection makefile for:	libircclient
# Date created:				2008-11-20
# Whom:					Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libircclient
PORTVERSION=	1.6
CATEGORIES=	irc devel
MASTER_SITES=	SF

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	An IRC library to create IRC clients

OPTIONS=	SSL	"Build with SSL Support" on \
		IPV6	"Build with IPv6 Support" on

BUILD_WRKSRC=	${WRKSRC}/src
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--enable-openssl
USE_OPENSSL=	yes
.endif

.if !defined(WITHOUT_IPV6)
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
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "installing additional examples to ${EXAMPLESDIR}"
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
