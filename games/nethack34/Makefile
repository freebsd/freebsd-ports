# New ports collection makefile for:	nethack
# Date created:		27 March 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	3.3.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.nethack.org/pub/nethack/nh${PORTVERSION:S/.//g}/src/
MASTER_SITE_SUBDIR=	nethack
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dscheidt@enteract.com

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XPM=	yes
USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nethack
	${CP} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/share/doc/nethack
.endif

.include <bsd.port.mk>
