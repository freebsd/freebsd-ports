# New ports collection makefile for:    tkhfs
# Date created:         17 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	tkhfs
PORTVERSION=	1.27
PORTREVISION=	3
CATEGORIES=	emulators tk
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tcl/Tk front end to the hfs program

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_TK=		yes
PLIST_FILES=	bin/tkhfs
RUN_DEPENDS=	hfs:${PORTSDIR}/emulators/hfs

.include <bsd.port.mk>
