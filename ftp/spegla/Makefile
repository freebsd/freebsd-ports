# ex:ts=8
# New ports collection makefile for:    spegla
# Version required:     0.93p2
# Date created:         Sun Apr 19 16:17:25 PDT 1998
# Whom:                 Jordan Hubbard <jkh@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/04/20 01:57:29 jkh Exp $
#

DISTNAME=	spegla-0.93p2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.luth.se/pub/unix/mirror/

MAINTAINER=     jkh@FreeBSD.org

WRKSRC=		${WRKDIR}/spegla

post-install:
	@${MKDIR} ${PREFIX}/share/examples/spegla
	${INSTALL_DATA} ${WRKSRC}/freebsd.org ${PREFIX}/share/examples/spegla

.include <bsd.port.mk>
