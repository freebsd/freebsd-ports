# New ports collection makefile for:	xmms-musepack
# Date created:			15 Mar 2002
# Whom:				Walter Hop <walter@binity.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-musepack
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://dl.slik.org/musepack/

MAINTAINER=	wh@slik.org
COMMENT=	XMMS input plugin for playing MPC Musepack (.mpc, .mp+) files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/xmms-mpegplus-1.8.0.so
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,gcc,${CC} ${CFLAGS} -fPIC," ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${PREFIX}/lib/xmms/Input/xmms-mpegplus-1.8.0.so

.include <bsd.port.post.mk>
