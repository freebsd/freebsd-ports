# New ports collection makefile for:    Dylan
# Version required:     2.0
# Date created:         23 Jan 1998
# Whom:                 housel@acm.org
#
# $Id: Makefile,v 1.1.1.1 1998/07/12 21:58:07 hsu Exp $
#

DISTNAME=	gd20-source
PKGNAME=	dylan-2.0
CATEGORIES=	lang
MASTER_SITES=	http://legend.gwydion.cs.cmu.edu/gwydion/dylan/release/

MAINTAINER= 	housel@acm.org

WRKSRC=		$(WRKDIR)/src

BROKEN=		"Awaiting installation of local distfile"
GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix=$(PREFIX) --srcdir=$(WRKSRC)
CONFIGURE_ENV=	D2C="$(WRKDIR)/d2c -p$(WRKSRC)/d2c/compiler/platforms.descr"

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	default

post-extract:
	uudecode -p $(FILESDIR)/d2c.gz.uu | $(GUNZIP_CMD) > $(WRKDIR)/d2c
	chmod ugo+x $(WRKDIR)/d2c

.include <bsd.port.mk>
