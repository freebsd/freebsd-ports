# New ports collection makefile for:	logo
# Version required:	3.1
# Date created:		22 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.6 1995/04/15 22:55:30 jmacd Exp $
#

DISTNAME=	ucblogo
PKGNAME=	ucblogo-3.1
CATEGORIES+=	languages
MASTER_SITES=	ftp://anarres.cs.berkeley.edu/pub/ucblogo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmacd@FreeBSD.ORG

MAKEFILE=	makefile
MAKE_FLAGS+=	"LIBLOC = ${PREFIX}/lib/logo"
WRKSRC=	${WRKDIR}
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
