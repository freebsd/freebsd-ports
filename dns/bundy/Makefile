# Created by: Jeremy C. Reed
# $FreeBSD$

PORTNAME=	bundy
PORTVERSION=	0.20150304
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	LOCAL/mat/bundy GH

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
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
LIB_DEPENDS=	libbotan-1.10.so:${PORTSDIR}/security/botan110 \
		liblog4cplus.so:${PORTSDIR}/devel/log4cplus \
		libicuuc.so:${PORTSDIR}/devel/icu \
		libgmp.so:${PORTSDIR}/math/gmp \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	bundy-dns
GH_TAGNAME=	97ac840

USE_OPENSSL=	yes

USES=	compiler:c++11-lang pathfix pkgconfig libtool python:3 autoreconf

USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var	\
		--without-werror \
		--enable-install-configurations

OPTIONS_DEFINE=	DOCS

PLIST_SUB=	PYTHON_SUFFIX=cpython-${PYTHON_SUFFIX}

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/cmdctl-certfile.pem ${STAGEDIR}${ETCDIR}/cmdctl-certfile.pem.sample
	${MV} ${STAGEDIR}${ETCDIR}/cmdctl-keyfile.pem ${STAGEDIR}${ETCDIR}/cmdctl-keyfile.pem.sample

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
