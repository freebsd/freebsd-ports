# New ports collection makefile for:	cpm-emulator
# Date created:		28 June 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	cpmemu
PORTVERSION=	0.2.1.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/emulators
DISTNAME=	cpm-0.2.1

PATCH_SITES=	${MASTER_SITE_SUNSITE}
PATCH_SITE_SUBDIR=	system/emulators
PATCHFILES=	cpm-0.2.1-glibc-rjm.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cpm emulator

ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
