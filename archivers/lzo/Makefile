# New ports collection makefile for:	lzo
# Version required:			1.04
# Date created:				21 Feb 1998
# Whom:					giffunip@asme.org
#
# $FreeBSD$
#

DISTNAME=	lzo-1.06
CATEGORIES=	archivers devel
MASTER_SITES= 	${MASTER_SITE_SUNSITE} \
		http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/
MASTER_SITE_SUBDIR=	libs/compression

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/lzo
	${INSTALL_DATA}	${WRKSRC}/doc/* ${PREFIX}/share/doc/lzo
.endif

.include <bsd.port.mk>
