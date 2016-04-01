# Created by: db
# $FreeBSD$

PORTNAME=	cwirc
PORTVERSION=	2.0.0
PORTREVISION=	5
CATEGORIES=	irc comms hamradio
MASTER_SITES=	http://myspace.voo.be/pcoupard/cwirc/download/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	X-Chat Morse plugin

LICENSE=	GPLv2

BUILD_DEPENDS=	xchat:irc/xchat

USES=		pkgconfig

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%STAGEDIR%%|${STAGEDIR}|' ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in COPYING LISEZMOI README RELEASE_NOTES
	${INSTALL_DATA}  ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/schematics
.for f in cw_oscillator.jpg rs232_key_connection.jpg
	${INSTALL_DATA} ${WRKSRC}/schematics/$f ${STAGEDIR}${DOCSDIR}/schematics
.endfor

.include <bsd.port.mk>
