# Created by: David Shane Holden <dpejesh@yahoo.com>
# $FreeBSD$

PORTNAME=	kronosnet
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	https://kronosnet.org/releases/

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Network abstraction layer designed for high availability

LICENSE=	GPLv2

LIB_DEPENDS=	liblzo2.so:archivers/lzo2 \
		liblz4.so:archivers/liblz4 \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libqb.so:devel/libqb

USES=		autoreconf gmake libtool localbase pkgconfig ssl # tar:xz
USE_BINUTILS=	yes
USE_GCC=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-B${LOCALBASE}/bin

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	MANPAGES DOCS
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	doxygen:devel/doxygen
MANPAGES_CONFIGURE_ENABLE=	man

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT} == base
EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-ssl-base-configure.ac
CONFIGURE_ENV=	openssl_CFLAGS=-I/usr/include openssl_LIBS=-lcrypto
.elif ${SSL_DEFAULT} == libressl
EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-ssl-libressl-configure.ac
.endif

.include <bsd.port.mk>
