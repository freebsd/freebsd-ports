# New ports collection makefile for:    tkhfs
# Date created:         17 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	tkhfs
PORTVERSION=	1.27
CATEGORIES=	emulators tk82
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz
DISTNAME=	${PORTNAME}

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A Tcl/Tk front end to the hfs program

PLIST_FILES=	bin/tkhfs
RUN_DEPENDS=	hfs:${PORTSDIR}/emulators/hfs \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

.include <bsd.port.mk>
