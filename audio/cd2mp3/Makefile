# New ports collection makefile for:	cd2mp3
# Date created:				4 January 2000
# Whom:					Jamie Heckford <jamie@jamiesdomain.co.uk>
#
# $FreeBSD$
#

PORTNAME=		cd2mp3
PORTVERSION=		0.81
PORTEPOCH=		1
CATEGORIES=		audio
# both the NS servers for cd2mp3.org.uk are lame.
# Informed maintainer - edwin 20021226
MASTER_SITES=		http://download.cd2mp3.org.uk/${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=		jamie@jamiesdomain.org.uk

RUN_DEPENDS=		lame:${PORTSDIR}/audio/lame/ \
			dagrab:${PORTSDIR}/audio/dagrab

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/cd2mp3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cd2mp3 ${PREFIX}/bin/cd2mp3
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cd2mp3
	${INSTALL_DATA}  ${WRKSRC}/README ${PREFIX}/share/doc/cd2mp3/README
.endif

.include <bsd.port.mk>
