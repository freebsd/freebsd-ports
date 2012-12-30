# Created by: Maxim Samsonov <xors@sendmail.ru>
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	0.70
PORTREVISION=	6
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMESUFFIX=	-qt3
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	xors@mailup.net
COMMENT=	Qt3 bindings for the D-BUS messaging system

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		qt-mt:${PORTSDIR}/x11-toolkits/qt33

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	QTDIR=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PLIST_SUB=	VERSION="1.0"

.include <bsd.port.mk>
