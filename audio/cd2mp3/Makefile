# New ports collection makefile for:	cd2mp3
# Date created:				4 January 2000
# Whom:					Jamie Heckford <jamie@blackhole.net>
#
# $FreeBSD$
#

PORTNAME=	cd2mp3
PORTVERSION=	0.82
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.blackh0le.net/cd2mp3/dist/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use CD Ripping and MP3 Encoding tool

RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame/ \
		dagrab:${PORTSDIR}/audio/dagrab

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/cd2mp3

PLIST_FILES=	bin/cd2mp3
PORTDOCS=	README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cd2mp3 ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
