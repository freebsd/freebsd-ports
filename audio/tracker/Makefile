# New ports collection makefile for:    tracker
# Version required:     4.43
# Date created:         2 Oct 1994
# Whom:                 swallace
#
# $Id: Makefile,v 1.25 1995/09/18 16:50:10 ache Exp $
#

DISTNAME=       tracker
PKGNAME=        tracker-4.43
CATEGORIES+=	audio
MASTER_SITES=   ftp://ftp.ens.fr/pub/dmi/users/espie/beta/
DISTFILES=      tracker-4.43.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

USE_GMAKE=      yes
MAKE_FLAGS=     MACHINE=freebsd CC=$(CC) INSTALL=$(INSTALL) -f

post-install:
	-cd ${WRKSRC}/Docs; makeinfo --no-split tracker.texinfo -o tracker.info; \
	cd ${WRKSRC}/Docs; gzip tracker.info; $(INSTALL) -m 644 -o bin -g bin tracker.info.gz ${PREFIX}/info

.include <bsd.port.mk>
