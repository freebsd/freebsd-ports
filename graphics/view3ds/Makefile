# New ports collection makefile for:	view3ds
# Date created:				18 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	view3ds
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lib3ds

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	3ds.1:${PORTSDIR}/graphics/lib3ds

USE_X_PREFIX=	yes
USE_QT_VER=	2
USE_MESA=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-fno-rtti -fno-exceptions" \
		LDFLAGS="-lm ${PTHREAD_LIBS}" \
		QTDIR=${X11BASE}

.include <bsd.port.mk>
