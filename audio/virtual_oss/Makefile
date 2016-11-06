# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual_oss
PORTVERSION=	1.1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Virtual OSS multi-device mixer application

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate

USES=		tar:bzip2 uidfix

OPTIONS_DEFINE=	BLUETOOTH DEBUG
OPTIONS_DEFAULT=BLUETOOTH

.if exists(/usr/lib/libcuse.so)
MAKE_ARGS=	HAVE_CUSE="YES"
.else
BUILD_DEPENDS+=	cuse4bsd-kmod>=0.1.24:multimedia/cuse4bsd-kmod
LIB_DEPENDS+=	libcuse4bsd.so:multimedia/cuse4bsd-kmod
.endif

BLUETOOTH_DESC=	Build with bluetooth support
BLUETOOTH_MAKE_ARGS=	HAVE_BLUETOOTH="YES"
DEBUG_MAKE_ARGS=	HAVE_DEBUG="YES"

PLIST_FILES=	sbin/virtual_oss \
		man/man8/virtual_oss.8.gz

MAKE_ARGS+=	PTHREAD_LIBS="-lpthread"

.include <bsd.port.mk>
