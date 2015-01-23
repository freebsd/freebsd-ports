# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-dev-tools
PORTVERSION=	4.10.0
PORTREVISION=	1
CATEGORIES=	devel xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 development tools

RUN_DEPENDS=	autoconf-2.69:${PORTSDIR}/devel/autoconf \
		automake-1.15:${PORTSDIR}/devel/automake \
		libtoolize:${PORTSDIR}/devel/libtool

GNU_CONFIGURE=	yes
USE_XFCE=	configenv	# to get MASTER_SITE_SUBDIR something has to be defined
USE_GNOME=	glib20
USES=		pkgconfig tar:bzip2

.include <bsd.port.mk>
