# New ports collection makefile for:	nethack
# Version required:	3.2.1 + 1.0.5.4.1
# Date created:		13 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.17 1997/07/12 16:53:39 max Exp $
#

DISTNAME=	nethack-3.2.1
PKGNAME=	ja-nethack-1.0.5.4.1
CATEGORIES=	japanese games
MASTER_SITES=	${MASTER_SITE_GNU}

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/nethack/
PATCHFILES=	jnethack-1.0.5.4.gz jnethack-1.0.5.4.1.gz

MAINTAINER=	max@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
MAN6=		dlb.6 dgn_comp.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; chmod 644 *.6
	@cd ${WRKSRC}/doc; ${MAKE} PREFIX=${PREFIX} manpages

.include <bsd.port.mk>
