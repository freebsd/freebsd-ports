# New ports collection makefile for:    tracker
# Version required:     4.41
# Date created:         2 Oct 1994
# Whom:                 swallace
#
# $Id: Makefile,v 1.22 1995/07/04 00:36:44 ache Exp $
#

DISTNAME=       tracker
PKGNAME=        tracker-4.41
CATEGORIES+=	audio
MASTER_SITES=   ftp://ftp.ens.fr/pub/dmi/users/espie/beta/
DISTFILES=      tracker-4.41.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

USE_GMAKE=      yes
MAKE_FLAGS=     MACHINE=freebsd CC=$(CC) INSTALL=$(INSTALL) -f

post-install:
	-cd ${WRKSRC}/Docs; makeinfo --no-split tracker.texinfo -o tracker.info; \
	cd ${WRKSRC}/Docs; gzip tracker.info; $(INSTALL) -m 644 -o bin -g bin tracker.info.gz ${PREFIX}/info

.include <bsd.port.mk>
