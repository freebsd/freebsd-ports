# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian
PORTVERSION=	1.4.13
DISTVERSIONPREFIX=	bindings-
CATEGORIES=	databases
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	php-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP binding for Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xapian-core>=${PORTVERSION}:databases/xapian-core
LIB_DEPENDS=	libxapian.so:databases/xapian-core

CONFLICTS_INSTALL=	xapian-bindings12

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang libtool php:build tar:xz

CONFIGURE_ARGS=	--datarootdir=${DATADIR} \
		--docdir=${DOCSDIR} \
		--enable-shared \
		--enable-static \
		--with-php7 \
		--without-csharp \
		--without-java \
		--without-lua \
		--without-perl \
		--without-php \
		--without-python \
		--without-python3 \
		--without-ruby \
		--without-tcl
CONFIGURE_ENV=	PHP_CONFIG=${LOCALBASE}/bin/php-config
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11

PLIST_SUB=	PHP_EXT_DIR=${PHP_EXT_DIR}

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' ${WRKSRC}/configure

.include <bsd.port.mk>
