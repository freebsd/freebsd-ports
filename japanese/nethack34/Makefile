# New ports collection makefile for:	nethack
# Version required:	3.2.1 + 1.0.5.2
# Date created:		13 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.6 1996/09/17 08:44:10 max Exp $
#

DISTNAME=	nethack-3.2.1
PKGNAME=	jp-nethack-1.0.5.2
CATEGORIES+=	japanese games
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.games/

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/jnethack/
PATCHFILES=	jnethack-1.0.5.2.gz

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
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man6/dgn_comp.6
	gzip -9nf ${PREFIX}/man/man6/lev_comp.6
	gzip -9nf ${PREFIX}/man/man6/nethack.6
	gzip -9nf ${PREFIX}/man/man6/recover.6
.endif

.include <bsd.port.mk>
