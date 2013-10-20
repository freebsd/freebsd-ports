# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libdap
PORTVERSION=	3.12.1
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
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		charsetfix gmake pathfix

.include <bsd.port.mk>
