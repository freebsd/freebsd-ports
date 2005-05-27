# New ports collection makefile for:  hsetroot
# Date created:        30 November 2003
# Whom:                Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	hsetroot
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to compose wallpapers for X

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2

PLIST_FILES=	bin/hsetroot
USE_X_PREFIX=	YES

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include 	<bsd.port.mk>
