# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libdap
PORTVERSION=	3.13.3
CATEGORIES=	devel
MASTER_SITES=	http://www.opendap.org/pub/source/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SDK which contains an implementation of DAP 2.0 and 3.1

LICENSE=	LGPL21

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libxml2.so:${PORTSDIR}/textproc/libxml2

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		charsetfix gmake libtool pathfix

.include <bsd.port.mk>
