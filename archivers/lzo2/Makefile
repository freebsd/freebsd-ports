# New ports collection makefile for:	lzo
# Version required:			1.04
# Date created:				21 Feb 1998
# Whom:					giffunip@asme.org
#
# $Id: Makefile,v 1.2 1998/12/01 23:12:55 billf Exp $
#

DISTNAME=       lzo-1.04
CATEGORIES=	archivers devel
MASTER_SITES=   ftp://wildsau.idv.uni-linz.ac.at/pub/mfx/lzo/ \
		ftp://ftp.uni-koeln.de/util/arc/ \
		ftp://ftp.rhrz.uni-bonn.de/pub-koeln/util/arc/ \
		ftp://ftp.all.de/pub/unix/tools/archivers/lzo/ \
		ftp://ftp.fu-berlin.de/pub/unix/tools/archivers/lzo/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=libs/compression

MAINTAINER=     ports@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= 	--enable-shared=yes \
  			--enable-asm=yes
post-install:

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/lzo
	${INSTALL_DATA}	${WRKSRC}/doc/* ${PREFIX}/share/doc/lzo
.endif

.include <bsd.port.mk>
