# New ports collection makefile for:	nethack
# Version required:	3.2.2
# Date created:		27 March 1995
# Whom:			asami
#
# $Id: Makefile,v 1.17 1998/11/21 00:48:19 flathill Exp $
#

DISTNAME=	nethack-3.2.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.wtower.com/nethack/sources/ \
		${MASTER_SITE_GNU}

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; chmod 644 *.6
	@cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nethack
	${CP} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/share/doc/nethack
.endif

.include <bsd.port.mk>
