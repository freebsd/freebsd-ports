# New ports collection makefile for:	xfce4-dev-tools
# Date created:		19 April 2006
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-dev-tools
PORTVERSION=	4.4.0
CATEGORIES=	devel xfce
MASTER_SITES=	${MASTER_SITES_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 development tools

RUN_DEPENDS=	${LOCALBASE}/gnu-autotools/bin/autoconf:${PORTSDIR}/devel/gnu-autoconf \
		${LOCALBASE}/gnu-autotools/bin/automake:${PORTSDIR}/devel/gnu-automake \
		${LOCALBASE}/bin/libtool:${PORTSDIR}/devel/libtool15

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_XFCE=	configenv	# to get MASTER_SITE_SUBDIR something has to be defined

post-patch:
	@${REINPLACE_CMD} -e '12s|^$$|PATH="$${PATH}:${LOCALBASE}/gnu-autotools/bin"|' \
		${WRKSRC}/scripts/xdt-autogen.in

.include <bsd.port.mk>
