# Created by: Jeremy C. Reed
# $FreeBSD$

PORTNAME=	bundy
PORTVERSION=	0.20140524
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	GH GHC LOCAL/mat/bundy

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Bundy DNS server suite

LICENSE=	ISC
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	ISC License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/boost/interprocess/sync/interprocess_upgradable_mutex.hpp:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/include/log4cplus/logger.h:${PORTSDIR}/devel/log4cplus \
		sqlite3>=3.3.9:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
LIB_DEPENDS=	libbotan-1.10.so:${PORTSDIR}/security/botan110 \
		liblog4cplus.so:${PORTSDIR}/devel/log4cplus \
		libicuuc.so:${PORTSDIR}/devel/icu \
		libgmp.so:${PORTSDIR}/math/gmp \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	bundy-dns
GH_COMMIT=	b809bfb
GH_TAGNAME=	${GH_COMMIT}

USE_PYTHON=	3
USE_OPENSSL=	yes

USES=	compiler:c++11-lang pathfix pkgconfig libtool

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal autoconf automake autoheader libtoolize
PATHFIX_MAKEFILEIN=	Makefile.am
ACLOCAL_ARGS=	-I m4macros
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var	\
		--without-werror \
		--enable-install-configurations

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/cmdctl-certfile.pem ${STAGEDIR}${ETCDIR}/cmdctl-certfile.pem.sample
	${MV} ${STAGEDIR}${ETCDIR}/cmdctl-keyfile.pem ${STAGEDIR}${ETCDIR}/cmdctl-keyfile.pem.sample

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
