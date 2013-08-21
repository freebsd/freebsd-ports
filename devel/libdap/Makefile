# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libdap
PORTVERSION=	3.11.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.opendap.org/pub/source/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SDK which contains an implementation of DAP 2.0 and 3.1

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		xml2:${PORTSDIR}/textproc/libxml2

CONFIGURE_ARGS=	--with-zlib=/usr
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		gmake pathfix

MAN1=		dap-config.1 \
		getdap.1

post-patch:
	# do not alter ${PREFIX}/lib/charset.alias
	@${REINPLACE_CMD} -e '/^install-exec-am: / s|install-exec-local||' ${WRKSRC}/gl/Makefile.in

.include <bsd.port.mk>
