# New ports collection makefile for:	xmcd
# Version required:	1.4
# Date created:		16 Februar 1995
# Whom:			gena
#
# $Id: Makefile,v 1.2 1995/04/01 12:44:07 jkh Exp $
#

DISTNAME=	xmcd-1.4
CATEGORIES+=	audio
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/xmcd/
DISTFILES=	xmcd-1.4.tar.gz

USE_IMAKE=	yes
IS_INTERACTIVE=	yes

pre-install:
	@(cd ${WRKSRC}; ${MAKE} Makefiles)

.include <bsd.port.mk>
