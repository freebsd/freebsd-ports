# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTREVISION=	22
CATEGORIES=	audio
PKGNAMEPREFIX=	cpp-

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	C++ Bindings for XMMS2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	${LOCALBASE}/include/boost/bind.hpp:devel/boost-libs
LIB_DEPENDS=	libxmmsclient.so:audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2
USES=		gnome python:2.7,build ssl
USE_LDCONFIG=	yes
USE_GNOME=	glib20

BROKEN_SSL=	openssl

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	cpp

.include "${MASTERDIR}/Makefile"
