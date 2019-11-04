# Created by: Fredrik Carlsson <fredrik@wasadata.com>
# $FreeBSD$

PORTNAME=	tetrinet
PORTVERSION=	0.11
CATEGORIES=	games net
MASTER_SITES=	http://tetrinet.or.cz/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console tetrinet client

USES=		ncurses
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DHAVE_IPV6 -fno-builtin-log"
PLIST_FILES=	bin/tetrinet bin/tetrinet-server

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README tetrinet.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-log/n; s/[[:<:]]log[[:>:]]/dolog/g' \
		${WRKSRC}/tetrinet.h ${WRKSRC}/tetrinet.c ${WRKSRC}/sockets.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tetrinet ${WRKSRC}/tetrinet-server \
		${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/tetrinet.txt \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
