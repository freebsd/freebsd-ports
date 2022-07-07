# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	xapian
PORTVERSION=	1.4.20
DISTVERSIONPREFIX=	bindings-
CATEGORIES=	databases
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lua binding for Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xapian-core>=${PORTVERSION}:databases/xapian-core
LIB_DEPENDS=	libxapian.so:databases/xapian-core

USES=		compiler:c++11-lang libtool lua:module tar:xz

CONFIGURE_ARGS=	--datarootdir=${DATADIR} \
		--docdir=${DOCSDIR} \
		--enable-shared \
		--enable-static \
		--with-lua \
		--without-csharp \
		--without-java \
		--without-perl \
		--without-php \
		--without-php7 \
		--without-python \
		--without-python3 \
		--without-ruby \
		--without-tcl
CONFIGURE_ENV=	LUA="${LUA_CMD}" LUA_INC="${LUA_INCDIR}" LUA_LIB="${LUA_MODLIBDIR}" LUA_SO=.so
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11

DOCSDIR=	${LUA_DOCSDIR}

CONFLICTS_INSTALL=	xapian-bindings12

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' ${WRKSRC}/configure

.include <bsd.port.mk>
