# New ports collection makefile for:	nethack
# Version required:	3.2.2 + 1.0.5.19970924
# Date created:		13 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.21 1998/09/17 00:32:43 asami Exp $
#

DISTNAME=	nethack-3.2.2
PKGNAME=	ja-nethack-1.0.5.19970924
CATEGORIES=	japanese games
MASTER_SITES=	${MASTER_SITE_GNU}

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/nethack/
PATCHFILES=	jnethack-1.0.5.19970924.gz

MAINTAINER=	max@FreeBSD.ORG

BROKEN_ELF=	yes

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
MAN6=		dlb.6 dgn_comp.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; chmod 644 *.6
	@cd ${WRKSRC}/doc; ${MAKE} PREFIX=${PREFIX} manpages

.include <bsd.port.mk>
