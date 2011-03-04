# New ports collection makefile for:	tangogps
# Date created:				4 Marth 2009
# Whom:					stas
#
# $FreeBSD$
#

PORTNAME=	tangogps
PORTVERSION=	0.99.4
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	http://www.tangogps.org/downloads/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A comprehencive GPS mapping application

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		exif.12:${PORTSDIR}/graphics/libexif \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USE_AUTOTOOLS=	automake aclocal libtool autoconf
ACLOCAL_ARGS=	--force
AUTCONF_ARGS=	--force
AUTOMAKE_ARGS=	--force
GNU_CONFIGURE=	yes

USE_GNOME=	gtk20 gconf2 libxml2
USE_SQLITE=	3
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
