# New ports collection makefile for:	logo
# Version required:	3.3
# Date created:		22 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.12 1998/11/28 05:39:01 asami Exp $
#

DISTNAME=	ucblogo-3.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	ucblogo

MAINTAINER=	jmacd@FreeBSD.ORG

USE_XLIB=	yes
MAKEFILE=	makefile
MAKE_FLAGS+=	"LIBLOC = ${PREFIX}/lib/logo"
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
