# New ports collection makefile for:	xcircuit
# Version required:	1.7
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $Id: Makefile,v 1.1.1.1 1998/05/18 04:20:21 mph Exp $
#

DISTNAME=	xcircuit-1.7
CATEGORIES=	cad x11
MASTER_SITES=	ftp://bach.ece.jhu.edu/pub/tim/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=apps/circuits

MAINTAINER=     ports@FreeBSD.ORG

USE_IMAKE=	yes
XMKMF=		xmkmf
ALL_TARGET=
INSTALL_TARGET=	install install.man

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/xcircuit
	${CP} ${WRKSRC}/examples/*.ps ${PREFIX}/share/examples/xcircuit
.endif

.include <bsd.port.mk>
