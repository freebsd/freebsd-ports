PORTNAME=	libdap
PORTVERSION=	3.21.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://www.opendap.org/pub/source/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SDK which contains an implementation of DAP 2.0 and 4.0
WWW=		https://www.opendap.org/software/libdap \
		https://github.com/OPENDAP/libdap4

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libuuid.so:misc/libuuid

USES=		bison:wrapper charsetfix gmake gnome libtool localbase pathfix ssl
USE_GNOME=	libxml2

CONFIGURE_ARGS=	ac_cv_lib_crypto_OpenSSL_add_all_algorithms=yes \
		ac_cv_type_max_align_t=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
