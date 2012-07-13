# New ports collection makefile for:	tetrinet
# Date created:		23 Februari 2001
# Whom:			Fredrik Carlsson <fredrik@wasadata.com>
#
# $FreeBSD$
#

PORTNAME=	tetrinet
PORTVERSION=	0.11
CATEGORIES=	games net ipv6
MASTER_SITES=	http://tetrinet.or.cz/download/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A console tetrinet client

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DHAVE_IPV6"
PLIST_FILES=	bin/tetrinet bin/tetrinet-server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README tetrinet.txt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet-server ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/tetrinet
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tetrinet
	${INSTALL_DATA} ${WRKSRC}/tetrinet.txt ${PREFIX}/share/doc/tetrinet
.endif

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
