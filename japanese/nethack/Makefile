# New ports collection makefile for:	nethack
# Version required:	3.2.1 + 1.0.5.2
# Date created:		13 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.4 1996/06/26 22:22:33 gpalmer Exp $
#

DISTNAME=	nethack-3.2.1
PKGNAME=	jp-nethack-1.0.5.2.2
CATEGORIES+=	japanese games
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.games/

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/jnethack/
PATCHFILES=	jnethack-1.0.5.1.gz jn-1.0.5.2-beta-960821.gz \
		jn-1.0.5.2-beta-960822.gz

MAINTAINER=	max@sfc.wide.ad.jp

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
