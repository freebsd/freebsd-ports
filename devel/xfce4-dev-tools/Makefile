# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-dev-tools
PORTVERSION=	4.10.0
CATEGORIES=	devel xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 development tools

RUN_DEPENDS=	${LOCALBASE}/share/autotools:${PORTSDIR}/devel/autotools

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_XFCE=	configenv	# to get MASTER_SITE_SUBDIR something has to be defined
USE_GNOME=	glib20
USES=		pkgconfig

.include <bsd.port.mk>
