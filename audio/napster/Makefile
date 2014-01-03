# Created by: dburr@FreeBSD.org
# $FreeBSD$

PORTNAME=	nap
PORTVERSION=	1.5.4
CATEGORIES+=	audio net
MASTER_SITES=	SF/nap/nap/${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	An MP3 sharing, search, and chat client for the OpenNAP network

CONFLICTS?=	ru-nap-*

GNU_CONFIGURE=	yes
NO_STAGE=	yes

MAN1=	nap.1

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in NEWS README doc/napster.txt doc/userguide.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
