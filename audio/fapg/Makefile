# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	fapg
PORTVERSION=	0.41
CATEGORIES=	audio
MASTER_SITES=	http://royale.zerezo.com/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Audio Playlist Generator

LIB_DEPENDS=	liburiparser.so:${PORTSDIR}/net/uriparser

MAKE_ARGS+=	CC="${CC}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-build:
	@cd ${WRKSRC} && ${MAKE} ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fapg.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in COPYING README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
