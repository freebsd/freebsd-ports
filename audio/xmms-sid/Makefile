# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-sid
PORTVERSION=	0.9.0
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS input plugin to play SID files

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USES=		gettext
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--with-sidplay1=${LOCALBASE}

.include <bsd.port.mk>
