# New ports collection makefile for:	cpm-emulator
# Version required:	0.2.1.1
# Date created:		28 June 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

DISTNAME=	cpm-0.2.1
PKGNAME=	cpmemu-0.2.1.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.cdrom.com/pub/linux/slackware-4.0/source/extra-stuff/CPM-80-emulator/
MASTER_SITE_SUBDIR=	system/emulators

PATCH_SITES=	${MASTER_SITE_SUNSITE}
PATCH_SITE_SUBDIR=	system/emulators
PATCHFILES=	cpm-0.2.1-glibc-rjm.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

.include <bsd.port.mk>
