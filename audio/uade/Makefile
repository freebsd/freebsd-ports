# New ports collection makefile for:	xmms-uade
# Date created:			12 Oct 2002
# Whom:				Martin Blapp <mbr@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-uade
PORTVERSION=	0.81
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://uade.ton.tut.fi/uade/
DISTNAME=	uade-${PORTVERSION}

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Unix Amiga Delitracker Emulator with XMMS Input plugin

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}/lib/xmms \
		--mymods=/ \
		--docprefix=${X11BASE}/lib/xmms \

CONFIGURE_ENV=	SYSCFLAGS='${CFLAGS}'

WRKSRC=		${WRKDIR}/uade-${PORTVERSION}

.include <bsd.port.mk>
