# New ports collection makefile for:    mplex
# Version required:     1.1
# Date created:         Wed Jul 31 20:54:54 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.3 1998/08/23 07:34:43 hoek Exp $
#

DISTNAME=	mplex-1.1

CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.informatik.tu-muenchen.de/pub/comp/graphics/mpeg/mplex/

MAINTAINER=	erich@FreeBSD.org

MAN1=		mplex.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mplex ${PREFIX}/bin
	@${INSTALL_MAN} ${FILESDIR}/mplex.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
