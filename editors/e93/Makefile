# New ports collection makefile for:	e93
# Version required:	1.2r5X
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.4 1995/09/12 22:47:20 asami Exp $
#

DISTNAME=	e93-1.2r5X
PKGNAME=	e93-1.2.5
CATEGORIES+=	editors
MASTER_SITES=	ftp://ftp.x.org/contrib/editors/ \
		ftp://crl.dec.com/pub/X11/contrib/editors/

MAINTAINER=	asami@FreeBSD.ORG

MAKEFILE=	makefile
USE_X11=	yes
WRKSRC=		${WRKDIR}/e93
RESTRICTED=	"Restrictive license."

do-install:
	if ! [ -d ${PREFIX}/lib/e93 ]; then mkdir ${PREFIX}/lib/e93; fi
	(cd ${WRKSRC}; \
	  install -c -s e93 ${PREFIX}/bin; \
	  install -c .e93rc ${PREFIX}/lib/e93; \
	)

.include <bsd.port.mk>
