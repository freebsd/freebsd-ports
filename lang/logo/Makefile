# New ports collection makefile for:	logo
# Version required:	3.1
# Date created:		22 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.3 1995/04/01 12:46:57 jkh Exp $
#

DISTNAME=	ucblogo
EXTRACT_SUFX=	.tar.Z
MASTER_SITES=	ftp://anarres.cs.berkeley.edu/pub/ucblogo/
CATEGORIES+=	languages
MAINTAINER=	jmacd@FreeBSD.ORG

MAKEFILE=	makefile
MAKE_FLAGS+=	"LIBLOC = ${PREFIX}/lib/logo"
WRKSRC=	${WRKDIR}
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
