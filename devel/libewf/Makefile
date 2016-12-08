# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libewf
PORTVERSION=	20140608
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/legacy/raw/master/libewf/ \
		LOCAL/antoine

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Library for support of the Expert Witness Compression Format (EWF)

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

USES=		fuse gettext iconv libtool:keepla pathfix pkgconfig python:2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python --with-libintl-prefix=${LOCALBASE} --with-libuuid=${LOCALBASE} ${ICONV_CONFIGURE_ARG} --with-libsmdev=no
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
