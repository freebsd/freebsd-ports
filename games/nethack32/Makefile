# New ports collection makefile for:	nethack
# Date created:		27 March 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	3.2.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.nethack.org/pub/nethack/nh322/src/ \
		ftp://ftp.wtower.com/nethack/sources/
DISTNAME=	nethack-3.2.2

PATCH_SITES=	ftp://ftp.nethack.org/pub/nethack/nh323/src/
PATCHFILES=	nh-3.2.2-3.2.3.diff

MAINTAINER=	glewis@FreeBSD.org

NO_LATEST_LINK=	yes

USE_XPM=	yes
USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
