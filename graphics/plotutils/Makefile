# New ports collection makefile for:	xfig
# Version required:	2.1.1
# Date created:		19 June 1998
# Whom:			Chuck Robey (chuckr)
#
# $Id: Makefile,v 1.1.1.1 1998/06/20 03:09:11 chuckr Exp $
#

DISTNAME=	plotutils-2.1.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	chuckr@FreeBSD.ORG

GNU_CONFIGURE=	yes

.ifdef HAVE_MOTIF
CONFIGURE_ARGS=	--with-motif
.endif

post-install:
	$(LDCONFIG) -m $(PREFIX)/lib

.include <bsd.port.mk>
