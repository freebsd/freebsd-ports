# ex:ts=8
# New ports collection makefile for:    spegla
# Version required:     0.93p2
# Date created:         Sun Apr 19 16:17:25 PDT 1998
# Whom:                 Jordan Hubbard <jkh@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/04/20 22:25:19 asami Exp $
#

DISTNAME=	spegla-1.03
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.luth.se/pub/unix/mirror/ \
		ftp://subzero.campus.luth.se/pub/spegla/

MAINTAINER=	jkh@FreeBSD.org

MANCOMPRESSED=	yes
MAN1=		spegla.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/spegla
	${INSTALL_DATA} ${WRKSRC}/freebsd.org ${PREFIX}/share/examples/spegla

.include <bsd.port.mk>
