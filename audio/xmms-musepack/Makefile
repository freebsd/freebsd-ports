# New ports collection makefile for:	xmms-musepack
# Date created:			15 Mar 2002
# Whom:				Walter Hop <walter@binity.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-musepack
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://dl.slik.org/musepack/

MAINTAINER=	wh@slik.org
COMMENT=	XMMS input plugin for playing MPC Musepack (.mpc, .mp+) files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes

post-install:
	${STRIP_CMD} ${PREFIX}/lib/xmms/Input/xmms-mpegplus-1.8.0.so

.include <bsd.port.mk>
