# New ports collection makefile for:	xmms-uade
# Date created:				12 Oct 2002
# Whom:					Martin Blapp <mbr@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-uade
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://zakalwe.virtuaalipalvelin.net/uade/uade/
DISTNAME=	uade-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix Amiga Delitracker Emulator with XMMS Input plugin

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool:15

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}/lib/xmms \
		--mymods=/ \
		--docdir=${X11BASE}/lib/xmms/doc/uade \

CONFIGURE_ENV=	SYSCFLAGS='${CFLAGS}'

WRKSRC=		${WRKDIR}/uade-${PORTVERSION}

MAN1=		uade.1

post-install:
		${RM} -rf ${X11BASE}/share/uade/players/S

.include <bsd.port.mk>
