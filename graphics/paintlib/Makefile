# New ports collection makefile for:	paintlib
# Date created:				18 June 2004
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	paintlib
PORTVERSION=	2.6.1
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.paintlib.de/paintlib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for processing images

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		ungif:${PORTSDIR}/graphics/libungif

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-SDL --disable-dfb
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,^${PREFIX}/,,}

MAN1=		paintlib-config.1

.include <bsd.port.mk>
