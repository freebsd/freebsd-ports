# New ports collection makefile for:	e93
# Version required:	1.0r2X
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.18 1995/04/23 10:33:33 asami Exp $
#

DISTNAME=	e93-1.0r2X
PKGNAME=	e93-1.0.2
CATEGORIES+=	editors
MASTER_SITES=	ftp://ftp.x.org/contrib/editors/ \
		ftp://crl.dec.com/pub/X11/contrib/editors/

MAINTAINER=	asami@FreeBSD.ORG

MAKEFILE=	makefile
USE_X11=	yes
# The license is a little scary, so disable packaging for now
NO_PACKAGE=	yes

do-install:
	if ! [ -d ${PREFIX}/lib/e93 ]; then mkdir ${PREFIX}/lib/e93; fi
	(cd ${WRKSRC}; \
	  install -c -s e93 ${PREFIX}/bin; \
	  install -c .e93rc ${PREFIX}/lib/e93; \
	)

.include <bsd.port.mk>
