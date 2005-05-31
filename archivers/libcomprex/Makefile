# ex:ts=8
# New ports collection makefile for:	libcomprex
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcomprex
PORTVERSION=	0.3.3
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnupdate

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparently handles automatic compression and decompression of files

#LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_LIBLTDL=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LIBTOOL_VER=	15
LIBTOOLFLAGS=	# none
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>
.include "Makefile.man"
.include <bsd.port.post.mk>
