# New ports collection makefile for:	nethack
# Version required:	3.1.3
# Date created:		27 March 1995
# Whom:			asami
#
# $Id: Makefile,v 1.3 1995/04/01 12:45:05 jkh Exp $
#

DISTNAME=	nethack3.1.3
PKGNAME=	nethack-3.1.3
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.games/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/nethack313
USE_GMAKE=	yes
SHELL=		/bin/sh

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SHELL} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; ${MAKE} manpages

.include <bsd.port.mk>
