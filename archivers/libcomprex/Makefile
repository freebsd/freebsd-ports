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

LICENSE=	LGPL21

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config
#LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

OPTIONS_DEFINE=	NLS

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>
.include "Makefile.man"
.include <bsd.port.post.mk>
