# New ports collection makefile for:    napster
# Date created:         Thu Nov 18 01:07:00 PST 1999
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nap
PORTVERSION=	1.5.3
CATEGORIES+=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nap

MAINTAINER?=	petef@FreeBSD.org
COMMENT?=	An MP3 sharing, search, and chat client for the OpenNAP network

CONFLICTS?=	ru-nap-*

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=	nap.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in NEWS README doc/napster.txt doc/userguide.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
