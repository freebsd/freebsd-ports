# ex:ts=8
# Ports collection makefile for:	ximp3
# Date created:			Jan 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ximp3
PORTVERSION=	0.1.15
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players/mp3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple console MP3 player

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
