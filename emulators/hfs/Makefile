# New ports collection makefile for:    hfs
# Version required:     0.37
# Date created:         17 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	hfs0_37
PKGNAME=	hfs-0.37
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.obs-besancon.fr/pub/outgoing/

MAINTAINER=	jmz@FreeBSD.org

USE_GMAKE=	yes
MAN1=		hfs.1

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/man1

.include <bsd.port.mk>
