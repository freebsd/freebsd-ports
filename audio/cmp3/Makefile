# New ports collection makefile for:	cmp3
# Date created:		10 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cmp3
PORTVERSION=	2.0.p6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.0-pre6
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ncurses based frontend to mpg123

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

WRKSRC=		${WRKDIR}/${PORTNAME}-kenrevs/

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	README sample.cmp3rc
PLIST_FILES=	bin/cmp3 bin/rnmp3

.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cmp3rc ${DOCSDIR}/sample.cmp3rc
.endif

.include <bsd.port.mk>
