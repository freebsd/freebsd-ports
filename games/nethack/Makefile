# New ports collection makefile for:	nethack
# Version required:	3.2.0
# Date created:		27 March 1995
# Whom:			asami
#
# $Id: Makefile,v 1.4 1995/04/11 00:20:17 asami Exp $
#

DISTNAME=	nethack-3.2.0
CATEGORIES+=	games
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/ \
	ftp://ftp.win.tue.nl/pub/games/nethack/General/Source/NH32/sources/

MAINTAINER=	asami@FreeBSD.ORG

NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
SHELL=		/bin/sh

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SHELL} setup.sh

post-install:
	@cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOMANCOMPRESS)
	for file in dgn_comp dlb lev_comp nethack recover; do \
	  gzip -9nf ${PREFIX}/man/man6/$$file.6; \
	done
.endif
.if !defined(NOPORTDOCS)
	mkdir -p ${PREFIX}/share/doc/nethack
	cp ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/share/doc/nethack
.endif

.include <bsd.port.mk>
