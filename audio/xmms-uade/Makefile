# New ports collection makefile for:	xmms-uade
# Date created:			12 Oct 2002
# Whom:				Martin Blapp <mbr@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-uade
PORTVERSION=	0.71
CATEGORIES=	audio
MASTER_SITES=	http://www.ee.tut.fi/%7Eheikki/uade/
DISTFILES=	uade-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mbr@FreeBSD.org

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms
BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}/lib/xmms \
		--mymods=/

WRKSRC=		${WRKDIR}/uade-${PORTVERSION}

.include <bsd.port.mk>
