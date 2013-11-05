# $FreeBSD$

PORTNAME=	xoscope
PORTVERSION=	2.0
CATEGORIES=	audio hamradio
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Sound card oscilloscope

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${STAGEDIR}${PREFIX} --sysconfdir=${STAGEDIR}${PREFIX}
USES=		gmake pkgconfig
USE_GNOME=	gtk20
USE_XORG=	x11

MAN1=		xoscope.1

.include <bsd.port.mk>
