# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/xmms_sndfile/
PKGNAMESUFFIX=	-sndfile
DISTNAME=	xmms_sndfile-${PORTVERSION}

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	XMMS plugin to allow playing libsndfile supported files

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		xmms.4:${PORTSDIR}/multimedia/xmms

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

PLIST_FILES=	lib/xmms/Input/libxmms_sndfile.so \
		lib/xmms/Input/libxmms_sndfile.a \
		lib/xmms/Input/libxmms_sndfile.la

USES=		pkgconfig
USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xmu xi
USE_LDCONFIG=	yes

.include <bsd.port.mk>
