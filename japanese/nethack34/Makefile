# New ports collection makefile for:	nethack
# Version required:	3.2.1 + 1.0.5.3-beta-960925
# Date created:		13 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.9 1996/10/05 11:24:38 max Exp $
#

DISTNAME=	nethack-3.2.1
PKGNAME=	jp-nethack-1.0.5.3.1
CATEGORIES+=	japanese games
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/jnethack/
PATCHFILES=	jnethack-1.0.5.3-beta-960925.gz

MAINTAINER=	max@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
SHELL=		/bin/sh
FETCH_BEFORE_ARGS=	-NP

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SHELL} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; chmod 644 *.6
	@cd ${WRKSRC}/doc; ${MAKE} PREFIX=${PREFIX} manpages

post-install:
	${COMPRESS_MAN} ${PREFIX}/man/man6/dlb.6
	${COMPRESS_MAN} ${PREFIX}/man/man6/dgn_comp.6
	${COMPRESS_MAN} ${PREFIX}/man/man6/lev_comp.6
	${COMPRESS_MAN} ${PREFIX}/man/man6/nethack.6
	${COMPRESS_MAN} ${PREFIX}/man/man6/recover.6

.include <bsd.port.mk>
