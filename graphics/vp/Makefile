# New ports collection makefile for:	vp
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	vp
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://math.smsu.edu/~erik/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image viewer for X

PLIST_FILES=	bin/vp
USE_SDL=	image
USE_GETOPT_LONG=yes
USE_LIBTOOL_VER=15
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_func_getopt_long=yes
USE_REINPLACE=	yes
MAN1=		vp.1

post-patch:
	${REINPLACE_CMD} 's@ getopt_long/Makefile@@g' ${WRKSRC}/configure

.include <bsd.port.mk>
