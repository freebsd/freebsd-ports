# New ports collection makefile for:	Plotmtv
# Version required:	 1.4.0
# Date created:		19 October 1996
# Whom:			pgs
#
# $Id: Makefile,v 1.1.1.1 1997/02/25 14:21:15 tg Exp $
#

DISTNAME=	Plotmtv1.4.0
PKGNAME=	plotmtv-1.4.0
CATEGORIES=	graphics
MASTER_SITES=   ftp://tanqueray.eecs.berkeley.edu/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
ALL_TARGET=	World
MAN1=		plotmtv.1

post-install:
	${INSTALL_MAN} $(WRKSRC)/Docs/plotmtv.man $(PREFIX)/man/man1/plotmtv.1
.if !defined(NOPORTDOCS)
	mkdir -p ${PREFIX}/share/doc/plotmtv
	${INSTALL_DATA} ${WRKSRC}/Docs/DataFormat.ps.Z \
		${PREFIX}/share/doc/plotmtv/
.endif

.include <bsd.port.mk>
