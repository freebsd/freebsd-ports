# New ports collection makefile for:    ncftp2
# Version required:     2.1.1
# Date created:         4 Nov 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.26 1995/08/18 17:50:34 peter Exp $
#

DISTNAME=       ncftp-2.1.1
CATEGORIES+=	networking
MASTER_SITES=   ftp://ftp.cs.unl.edu/pub/ncftp/
EXTRACT_SUFX=   .tgz

MAINTAINER=	ache@FreeBSD.ORG

GNU_CONFIGURE=  yes

do-install:
	cd ${WRKSRC}; $(INSTALL) $(COPY) $(STRIP) -o $(BINOWN) -g $(BINGRP) -m $(BINMODE) ncftp $(PREFIX)/bin/ncftp2
	cd ${WRKSRC}; $(INSTALL) -c -o $(BINOWN) -g $(BINGRP) -m 644 ncftp.1 $(PREFIX)/man/man1/ncftp2.1

# Copy the list of FreeBSD sites
pre-patch:
	cp ${FILESDIR}/Complete.h ${WRKSRC}
	cp ${FILESDIR}/Complete.c ${WRKSRC}

.include <bsd.port.mk>
