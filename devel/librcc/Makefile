# New ports collection makefile for:	librcc
# Date created:			30-12-2007
# Whom:				Ulrich Spoerlein <uspoerlein@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	librcc
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/rusxmms/Charset%20Conversion%20Library/${PORTVERSION}

MAINTAINER=	uspoerlein@gmail.com
COMMENT=	Library used by rusxmms for language autodetection

LIB_DEPENDS=	rcd.1:${PORTSDIR}/devel/librcd

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12 libxml2
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=--disable-bdb --disable-gtk2 --disable-glib2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
