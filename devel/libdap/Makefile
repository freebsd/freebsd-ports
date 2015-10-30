# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libdap
PORTVERSION=	3.16.0
CATEGORIES=	devel
MASTER_SITES=	http://www.opendap.org/pub/source/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SDK which contains an implementation of DAP 2.0 and 3.1

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libxml2.so:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		bison charsetfix gmake libtool localbase pathfix

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1100000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-dds.yy
.endif

.include <bsd.port.post.mk>
