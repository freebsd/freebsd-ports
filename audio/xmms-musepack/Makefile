# New ports collection makefile for:	xmms-musepack
# Date created:			15 Mar 2002
# Whom:				Walter Hop <walter@binity.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-musepack
PORTVERSION=	1.8.0
CATEGORIES=	audio
MASTER_SITES=	http://www.musepack.info/dl/

MAINTAINER=	walter@binity.com

LIB_DEPENDS=	xmms.3:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes

post-install:
	strip ${PREFIX}/lib/xmms/Input/xmms-mpegplus-1.8.0.so

.include <bsd.port.mk>
