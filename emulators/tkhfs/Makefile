# New ports collection makefile for:    tkhfs
# Date created:         17 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	tkhfs
PORTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	emulators tk84
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz
DISTNAME=	${PORTNAME}

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A Tcl/Tk front end to the hfs program

USE_TK=		yes
PLIST_FILES=	bin/tkhfs
RUN_DEPENDS=	hfs:${PORTSDIR}/emulators/hfs

.include <bsd.port.mk>
