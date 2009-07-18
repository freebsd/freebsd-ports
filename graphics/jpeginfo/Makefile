# New ports collection makefile for:    jpeginfo
# Date created:         9.8.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	jpeginfo
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	ache@freebsd.org
COMMENT=	Generate listing and MD5, check jpegs for error, delete broken ones

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ARGS=	mandir=${MANPREFIX}/man

MAN1=		jpeginfo.1
PLIST_FILES=	bin/jpeginfo

.include <bsd.port.mk>
