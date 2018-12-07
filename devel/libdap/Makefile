# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libdap
PORTVERSION=	3.20.2
CATEGORIES=	devel
MASTER_SITES=	https://www.opendap.org/pub/source/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SDK which contains an implementation of DAP 2.0 and 3.1

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libuuid.so:misc/e2fsprogs-libuuid \
		libxml2.so:textproc/libxml2

USES=		bison charsetfix gmake libtool localbase pathfix ssl

CONFIGURE_ARGS=	ac_cv_lib_crypto_OpenSSL_add_all_algorithms=yes \
		ac_cv_type_max_align_t=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
