# New ports collection makefile for:	naga10
# Version required:	1.0
# Date created:		25 Feb 1998
# Whom: Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $Id: Makefile,v 1.3 1998/08/05 09:31:17 asami Exp $
#

DISTNAME=	knj10-1.00
PKGNAME=	ja-naga10-1.0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://gondow-www.cs.titech.ac.jp/~snagao/fonts/

MAINTAINER=	usagi@clave.gr.jp

USE_X_PREFIX=	yes
WRKSRC=         ${WRKDIR}/knj10-1.00

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/naga10
	@${CP} ${WRKSRC}/README ${PREFIX}/share/doc/naga10/
.endif

.include <bsd.port.mk>
