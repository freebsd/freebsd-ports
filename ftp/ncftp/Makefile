# New ports collection makefile for:    ncftp2
# Version required:     1.9.5
# Date created:         20 Jun 1996
# Whom:                 jkh
#
# $Id$
#

DISTNAME=       ncftp-1.9.5
CATEGORIES+=	net
MASTER_SITES=   ftp://ftp.probe.net/pub/ncftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jkh@FreeBSD.ORG

do-install:
	cd ${WRKSRC}; $(INSTALL) -c $(STRIP) -o $(BINOWN) -g $(BINGRP) -m $(BINMODE) ncftp $(PREFIX)/bin
	cd ${WRKSRC}; $(INSTALL) -c -o $(BINOWN) -g $(BINGRP) -m 644 ncftp.1 $(PREFIX)/man/man1

.include <bsd.port.mk>
