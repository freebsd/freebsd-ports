# New ports collection makefile for:	nethack
# Version required:	3.1.3
# Date created:		13 February 1995
# Whom:			asami
#
# $Id:$
#

DISTNAME=	nethack3.1.3
PKGNAME=	jp-nethack-1.0.2
CATEGORIES+=	japanese games
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.games/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/jnethack/
PATCHFILES=	jnethack-1.0.2.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/nethack313
USE_GMAKE=	yes
SHELL=		/bin/sh

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SHELL} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; ${MAKE} manpages


post-install:
	gzip -9nf ${PREFIX}/man/man6/dgn_comp.6
	gzip -9nf ${PREFIX}/man/man6/lev_comp.6
	gzip -9nf ${PREFIX}/man/man6/nethack.6
	gzip -9nf ${PREFIX}/man/man6/recover.6

.include <bsd.port.mk>
