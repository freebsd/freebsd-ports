# New ports collection makefile for:	nethack
# Date created:		23 September 2000
# Whom:			Jeremy Chadwick <yoshi@parodius.com>
#
# $FreeBSD$
#

PORTNAME=	nethack
PKGNAMESUFFIX=	-tty
PORTVERSION=	3.3.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.nethack.org/pub/nethack/nh331/src/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	nethack
DISTFILES=	${PORTNAME}-331.${EXTRACT_SUFIX}

MAINTAINER=	yoshi@parodius.com

EXTRACT_SUFIX=	tgz
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
