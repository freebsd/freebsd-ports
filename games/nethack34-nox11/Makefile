# New ports collection makefile for:	nethack
# Version required:	3.1.3
# Date created:		27 March 1995
# Whom:			asami
#
# $Id: Makefile,v 1.2 1995/03/30 09:49:57 ats Exp $
#

DISTNAME=	nethack3.1.3
EXTRACT_SUFX=	.tar.Z
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.games/
CATEGORIES+=	games
MAINTAINER=	asami@FreeBSD.ORG
WRKSRC=		${WRKDIR}/nethack313
USE_GMAKE=	yes
PKGNAME=	nethack-3.1.3
SHELL=		/bin/sh

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SHELL} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; ${MAKE} manpages

.include <bsd.port.mk>
