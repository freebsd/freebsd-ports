# New ports collection makefile for:	xlog
# Date created:		2002-11-05
# Whom:			Patrick Gardella <patrick@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xlog
PORTVERSION=	0.9.1
PORTREVISION=   0
CATEGORIES=	comms
MASTER_SITES=   http://www.qsl.net/pg4i/download/

MAINTAINER=	patrick@FreeBSD.org
COMMENT=	An Amateur Radio station logging application

USE_GNOME=  	gtk20
GNU_CONFIGURE=	yes

MAN1=		xlog.1

.include <bsd.port.mk>

.if defined(WITH_HAMLIB)
LIB_DEPENDS=    hamlib-1.1.4.1:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=        --enable-hamlib
PLIST_SUB+=     HAMLIB=""
CONFIGURE_ENV=	PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
MAKE_ENV=	PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
.endif
