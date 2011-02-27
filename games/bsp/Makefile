# New ports collection makefile for:	bsp
# Date created:			22 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	bsp
PORTVERSION=	5.2
CATEGORIES=	games
MASTER_SITES=	http://games.moria.org.uk/doom/bsp/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Node builder for Doom

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN6=		bsp.6

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -fomit-frame-pointer|${CFLAGS} &|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bsp.6 ${MANPREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
