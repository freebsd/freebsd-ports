# New ports collection makefile for:    tracker
# Version required:     5.3
# Date created:         2 Oct 1994
# Whom:                 swallace
#
# $Id: Makefile,v 1.30 1997/11/26 02:05:15 jseger Exp $
#

DISTNAME=       tracker-5.3
CATEGORIES=     audio
MASTER_SITES=   ftp://ftp.uni-trier.de/pub/unix/audio/tracker/
EXTRACT_SUFX=   .tgz

MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=     "Non-redistributable beta"

WRKSRC=         ${WRKDIR}/tracker
USE_GMAKE=      yes
MAKE_FLAGS=     MACHINE=freebsd CC=$(CC) INSTALL="$(INSTALL)" \
		INST_BIN_OPT="-c -s -m $(BINMODE) -o $(BINOWN) -g $(BINGRP)" \
		INST_MAN_OPT="-c -m 644 -o $(BINOWN) -g $(BINGRP)" \
		COMPRESSION_FILE=$(PREFIX)/etc/compression_methods \
		-f

post-install:
	cd ${WRKSRC}/Docs && \
	makeinfo --no-split tracker.texinfo -o tracker.info && \
	gzip -f tracker.info && \
	$(INSTALL_MAN) tracker.info.gz ${PREFIX}/info && \
	${RM} -f tracker.info.gz *.orig
	-${MKDIR} ${PREFIX}/share/doc/tracker
	${CP} -R ${WRKSRC}/Docs/* ${PREFIX}/share/doc/tracker

.include <bsd.port.mk>
