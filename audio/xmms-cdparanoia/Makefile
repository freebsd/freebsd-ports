# New ports collection makefile for:	xmms-cdparanoia
# Date created:				2 May 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	cdparanoia
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www008.upp.so-net.ne.jp/kzmi/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-plugin-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Cdparanoia plugin for XMMS

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

.include <bsd.port.mk>
