# New ports collection makefile for:	lzo
# Version required:			1.04
# Date created:				21 Feb 1998
# Whom:					giffunip@asme.org
#
# $Id: Makefile,v 1.1.1.1 1998/12/01 23:11:12 billf Exp $
#

DISTNAME=       lzo-1.04
CATEGORIES=	archivers devel
MASTER_SITES=   ftp://wildsau.idv.uni-linz.ac.at/pub/mfx/lzo/	\
		ftp://tsx-11.mit.edu/pub/linux/sources/libs/	\
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
