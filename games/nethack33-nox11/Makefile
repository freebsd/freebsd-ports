# New ports collection makefile for:	nethack
# Version required:	3.1.3
# Date created:		27 March 1995
# Whom:			asami
#
# $Id:$
#

DISTNAME=	nethack3.1.3
EXTRACT_SUFX=	.tar.Z
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.games/
MAINTAINER=	asami@FreeBSD.ORG
WRKSRC=		${WRKDIR}/nethack313
USE_GMAKE=	yes
PKGNAME=	nethack-3.1.3

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SHELL} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; ${MAKE} manpages

.include <bsd.port.mk>
