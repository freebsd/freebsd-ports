# New ports collection makefile for:    lincity
# Date created:         13 Feb 1997
# Whom:                 Julian Assange
#
# $FreeBSD$
#

PORTNAME=	lincity
PORTVERSION=	1.12.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rich city simulation game for X

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		lincity.6

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=	--without-x
PLIST_SUB=	PROG="bin/lincity"
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=	--without-svga
PLIST_SUB=	PROG="bin/xlincity"
.endif

.include <bsd.port.mk>
