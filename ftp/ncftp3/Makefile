# New ports collection makefile for:    ncftp2
# Version required:     2.2.2
# Date created:         4 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.30 1995/11/23 20:37:59 ache Exp $
#

DISTNAME=       ncftp-2.2.2
CATEGORIES+=	net
MASTER_SITES=   ftp://ftp.cs.unl.edu/pub/ncftp/
EXTRACT_SUFX=   .tgz

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=  yes
CONFIGURE_ENV=  ac_cv_func_getmaxyx=yes

do-install:
	cd ${WRKSRC}; $(INSTALL) $(COPY) $(STRIP) -o $(BINOWN) -g $(BINGRP) -m $(BINMODE) ncftp $(PREFIX)/bin/ncftp2
	cd ${WRKSRC}; $(INSTALL) -c -o $(BINOWN) -g $(BINGRP) -m 644 ncftp.1 $(PREFIX)/man/man1/ncftp2.1

.include <bsd.port.mk>
