# New ports collection makefile for:	cmp3
# Date created:		10 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cmp3
PORTVERSION=	2.0.p5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ncurses based frontend to mpg123

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cmp3rc ${DOCSDIR}/sample.cmp3rc
.endif

.include <bsd.port.mk>
