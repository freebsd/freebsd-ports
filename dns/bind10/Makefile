# Created by: Jeremy C. Reed
# $FreeBSD$

PORTNAME=	bind10
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Development version of ISC BIND 10 DNS Suite

LICENSE=	ISC
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	ISC License
LICENSE_FILE=	${FILESDIR}/LICENSE
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

DEPRECATED=	Is not developed any more, use dns/bundy
EXPIRATION_DATE=	2015-12-31

USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USES=	compiler:c++11-lang pathfix pkgconfig python:3 libtool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var	\
		--without-werror \
		--enable-install-configurations

PLIST_SUB+=	PORTNAME=${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/cmdctl-certfile.pem ${STAGEDIR}${ETCDIR}/cmdctl-certfile.pem.sample
	${MV} ${STAGEDIR}${ETCDIR}/cmdctl-keyfile.pem ${STAGEDIR}${ETCDIR}/cmdctl-keyfile.pem.sample

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	You have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
