# New ports collection makefile for:    tracker
# Version required:     4.44
# Date created:         2 Oct 1994
# Whom:                 swallace
#
# $Id: Makefile,v 1.26 1995/10/16 07:13:12 ache Exp $
#

DISTNAME=       tracker
PKGNAME=        tracker-4.44
CATEGORIES+=	audio
MASTER_SITES=   ftp://ftp.ens.fr/pub/dmi/users/espie/beta/
DISTFILES=      tracker-4.44.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

USE_GMAKE=      yes
MAKE_FLAGS=     MACHINE=freebsd CC=$(CC) INSTALL="$(INSTALL)" \
		INST_BIN_OPT="-c -s -m $(BINMODE) -o $(BINOWN) -g $(BINGRP)" \
		INST_MAN_OPT="-c -m 644 -o $(BINOWN) -g $(BINGRP)" \
		COMPRESSION_FILE=$(PREFIX)/etc/compression_methods \
		-f

post-install:
	cd ${WRKSRC}/Docs; makeinfo --no-split tracker.texinfo -o tracker.info; \
	cd ${WRKSRC}/Docs; gzip -f tracker.info; \
	$(INSTALL) -c -m 644 -o $(BINOWN) -g $(BINGRP) tracker.info.gz ${PREFIX}/info

.include <bsd.port.mk>
