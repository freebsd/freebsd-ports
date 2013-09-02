# $FreeBSD$

PORTNAME=	msilbc
PORTVERSION=	2.0.3
CATEGORIES=	audio net
MASTER_SITES=	SAVANNAH/linphone/plugins/sources/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Mediastreamer plugin for the iLBC audio codec

LIB_DEPENDS=	ortp.8:${PORTSDIR}/net/linphone-base \
		mediastreamer.0:${PORTSDIR}/net/linphone-base \
		ilbc.0:${PORTSDIR}/net/ilbc

USES=		pkgconfig

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	ILBC_CFLAGS=-I${LOCALBASE}/include/ilbc \
		ILBC_LIBS="-L${LOCALBASE}/lib -lilbc"

.include <bsd.port.mk>
