# New ports collection makefile for:	xmcd
# Version required:	1.4
# Date created:		16 Februar 1995
# Whom:			gena
#
# $Id: Makefile,v 1.1.1.1 1995/02/17 10:53:05 jkh Exp $
#

DISTNAME=	xmcd-1.4
DISTFILES=	xmcd-1.4.tar.gz

MASTER_SITES=	ftp://ftp.x.org/contrib/applications/xmcd/
CATEGORIES+=	audio

USE_IMAKE=	yes
IS_INTERACTIVE=	yes

pre-install:
	@(cd ${WRKSRC}; ${MAKE} Makefiles)

.include <bsd.port.mk>
