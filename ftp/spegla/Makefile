# ex:ts=8
# New ports collection makefile for:    spegla
# Version required:     0.93p2
# Date created:         Sun Apr 19 16:17:25 PDT 1998
# Whom:                 Jordan Hubbard <jkh@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	spegla-0.93p2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.luth.se/pub/unix/mirror/

MAINTAINER=     jkh@FreeBSD.org

WRKSRC=		${WRKDIR}/spegla

post-install:
	@mkdir -p ${PREFIX}/share/examples/spegla
	${INSTALL} -c -m 444 ${WRKSRC}/freebsd.org ${PREFIX}/share/examples/spegla

.include <bsd.port.mk>
