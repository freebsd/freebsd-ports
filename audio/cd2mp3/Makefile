# New ports collection makefile for:	cd2mp3
# Date created:				4 January 2000
# Whom:					Jamie Heckford <jamie@jamiesdomain.co.uk>
#
# $FreeBSD$
#

PORTNAME=		cd2mp3
PORTVERSION=		1.1
CATEGORIES=		audio
MASTER_SITES=		ftp://ukug.uk.freebsd.org/pub/kandy/cd2mp3/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=		jamie@jamiesdomain.co.uk

RUN_DEPENDS=		bladeenc:${PORTSDIR}/audio/bladeenc/ \
			dagrab:${PORTSDIR}/audio/dagrab

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/cd2mp3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cd2mp3 ${PREFIX}/bin/cd2mp3
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/cd2mp3
	${INSTALL_DATA}  ${WRKSRC}/README ${PREFIX}/share/cd2mp3/README
.endif

.include <bsd.port.mk>
