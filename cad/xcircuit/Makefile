# New ports collection makefile for:	xcircuit
# Version required:	2.0a11
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

DISTNAME=	xcircuit-2.0a11
CATEGORIES=	cad
MASTER_SITES=	ftp://bach.ece.jhu.edu/pub/tim/xcircuit/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_BZIP2=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf

MAN1=		xcircuit.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/xcircuit
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/xcircuit
.endif

.include <bsd.port.mk>
