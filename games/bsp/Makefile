# New ports collection makefile for:	bsp
# Date created:			22 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	bsp
PORTVERSION=	5.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	doombsp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Node builder for Doom

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e "s,-O2 -fomit-frame-pointer -ffast-math,${CFLAGS}," \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
