# Created by: Jeremy C. Reed
# $FreeBSD$

PORTNAME=	bundy
PORTVERSION=	0.20170618
PORTREVISION=	11
CATEGORIES=	dns
MASTER_SITES=	LOCAL/mat/bundy SF/boost/boost/1.55.0:boost
DISTFILES+=	boost_1_55_0.tar.bz2:boost

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Bundy DNS server suite

LICENSE=	ISC
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	ISC License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/log4cplus/logger.h:devel/log4cplus \
		sqlite3>=3.3.9:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
LIB_DEPENDS=	libbotan-1.10.so:security/botan110 \
		liblog4cplus.so:devel/log4cplus \
		libgmp.so:math/gmp \
		libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

BROKEN_armv6 =		fails to build: Child process terminated abnormally: Segmentation fault
BROKEN_armv7 =		fails to build: Child process terminated abnormally: Segmentation fault
BROKEN_powerpc64=	fails to configure: checking for botan/botan.h... no

USES=	compiler:c++11-lang pathfix pkgconfig libtool python:3.4+ autoreconf ssl
USE_CSTD=	gnu99
USE_CXXSTD=	gnu++98
USE_GITHUB=	yes
GH_ACCOUNT=	bundy-dns
GH_TAGNAME=	e640032

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var	\
		--without-werror \
		--enable-install-configurations
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${WRKDIR}/boost_1_55_0

OPTIONS_DEFINE=	DOCS

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/cmdctl-certfile.pem ${STAGEDIR}${ETCDIR}/cmdctl-certfile.pem.sample
	${MV} ${STAGEDIR}${ETCDIR}/cmdctl-keyfile.pem ${STAGEDIR}${ETCDIR}/cmdctl-keyfile.pem.sample

.include <bsd.port.mk>
