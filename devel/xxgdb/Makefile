# New ports collection makefile for:	xxgdb
# Version required:     1.12
# Date created:		2 May 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.6 1997/12/25 22:29:15 asami Exp $
#

DISTNAME=	xxgdb-1.12
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	ports@FreeBSD.ORG

USE_IMAKE=	yes

# This isn't included in the original Imakefile for some reason.
#  Yes, I know this will recompile the program every time, but
#  we have the cookie anyway and it's much easier this way
#  than modifying the Imakefile.
post-build:
	cd ${WRKSRC}; gcc -o xxgdbiowin -O2 xxgdbiowin.c

post-install:
	install -c -s ${WRKSRC}/xxgdbiowin ${PREFIX}/bin

.include <bsd.port.mk>
