# Created by: dburr@FreeBSD.org
# $FreeBSD$

PORTNAME=	nap
PORTVERSION=	1.5.4
CATEGORIES+=	audio net
MASTER_SITES=	SF/nap/nap/${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	MP3 sharing, search, and chat client for the OpenNAP network

CONFLICTS?=	ru-nap-*

USES=		ncurses
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in NEWS README doc/napster.txt doc/userguide.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
