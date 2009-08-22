# New ports collection makefile for:    napster
# Date created:         Thu Nov 18 01:07:00 PST 1999
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nap
PORTVERSION=	1.5.4
CATEGORIES+=	audio net
MASTER_SITES=	SF/nap/nap/${PORTVERSION}

MAINTAINER?=	araujo@FreeBSD.org
COMMENT?=	An MP3 sharing, search, and chat client for the OpenNAP network

CONFLICTS?=	ru-nap-*

GNU_CONFIGURE=	yes

MAN1=	nap.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in NEWS README doc/napster.txt doc/userguide.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
