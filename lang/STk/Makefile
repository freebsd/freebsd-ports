# New ports collection makefile for:    STk
# Version required:     2.1
# Date created:         28 Dec 1994
# Whom:                 jmacd@uclink.berkeley.edu
#
# $Id: Makefile,v 1.9 1995/06/26 00:13:51 jmacd Exp $
#

DISTNAME=       STk-2.1.7
CATEGORIES+=	lang
MASTER_SITES=	ftp://kaolin.unice.fr/pub/

MAINTAINER=	jmacd@FreeBSD.ORG

IS_INTERACTIVE=	yes
GNU_CONFIGURE=	yes
MAKE_FLAGS=  	"prefix=${PREFIX}" -f

post-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
