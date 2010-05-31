# New ports collection makefile for:	libvisual
# Date created:		23 oktober 2004
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libvisual
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	04

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction library that sits between apps and visual plugin

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack pkgconfig
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
PLIST_SUB=	VER=-0.4

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-variable||g;s|-O3|${CFLAGS}|g' \
		${WRKSRC}/libvisual/Makefile.in
	@${REINPLACE_CMD} -e 's|sys/sched.h||g' -e '/test.*==/s|==|=|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e 's|$$<|$${.ALLSRC}|g'

.include <bsd.port.mk>
