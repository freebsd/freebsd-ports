# New ports collection makefile for:    hfs
# Date created:         17 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	hfs
PORTVERSION=	0.37
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Read Macintosh HFS floppy disks, hard drives and CDROMs

USE_GMAKE=	yes
MAN1=		hfs.1
PLIST_FILES=	bin/hfs

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/man1

.include <bsd.port.mk>
