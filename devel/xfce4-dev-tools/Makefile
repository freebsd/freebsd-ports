# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-dev-tools
PORTVERSION=	4.12.0
PORTREVISION=	1
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce development tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	autoconf-2.69:${PORTSDIR}/devel/autoconf \
		automake-1.15:${PORTSDIR}/devel/automake \
		libtoolize:${PORTSDIR}/devel/libtool \
		bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USES=		pkgconfig shebangfix tar:bzip2 xfce
SHEBANG_FILES=	scripts/xdt-commit

.include <bsd.port.mk>
