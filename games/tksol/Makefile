# New ports collection makefile for:    tksol
# Date created:         26 June 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tksol
PORTVERSION=	1.0
CATEGORIES=	games tk82
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/misc_software/tksol/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.org

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/release
MAN6=		tksol.6

.include <bsd.port.mk>
