# New ports collection makefile for:	xxgdb
# Version required:     1.12
# Date created:		2 May 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.3 1995/11/26 10:24:02 asami Exp $
#

DISTNAME=	xxgdb-1.12
CATEGORIES+=	devel
MASTER_SITES=   ftp://ftp.x.org/contrib/utilities/ \
		ftp://crl.dec.com/pub/X11/contrib/utilities/

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes

# This isn't included in the original Imakefile for some reason.
#  Yes, I know this will recompile the program every time, but
#  we have the cookie anyway and it's much easier this way
#  than modifying the Imakefile.
post-build:
	cd ${WRKSRC}; gcc -o xxgdbiowin -m486 -O2 xxgdbiowin.c

post-install:
	install -c -s ${WRKSRC}/xxgdbiowin ${PREFIX}/bin

.include <bsd.port.mk>
