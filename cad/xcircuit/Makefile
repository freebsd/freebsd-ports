# New ports collection makefile for:	xcircuit
# Version required:	1.7
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

DISTNAME=	xcircuit-1.7
CATEGORIES=	cad
MASTER_SITES=	ftp://bach.ece.jhu.edu/pub/tim/	\
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=apps/circuits

MAINTAINER=     ports@FreeBSD.org

BROKEN='bad MD5 checksum'

USE_IMAKE=	yes
XMKMF=		xmkmf
ALL_TARGET=
INSTALL_TARGET=	install install.man

MAN1=		xcircuit.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/xcircuit
	${CP} ${WRKSRC}/examples/*.ps ${PREFIX}/share/examples/xcircuit
.endif

.include <bsd.port.mk>
