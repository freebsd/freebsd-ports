# ex:ts=8
# New ports collection makefile for:	libcomprex
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcomprex
PORTVERSION=	0.3.3
PORTREVISION=	8
CATEGORIES=	archivers
MASTER_SITES=	SF/gnupdate/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparently handles automatic compression and decompression of files

#LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack gnometarget pkgconfig
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
USE_LDCONFIG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
BROKEN=		Does not build without gettext
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>
.include "Makefile.man"
.include <bsd.port.post.mk>
