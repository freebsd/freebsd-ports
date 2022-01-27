PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	4.0.28
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	dev.ashevchuk@gmail.com
COMMENT=	Distributed document-oriented "NoSQL" database (4.0.x Branch)

LICENSE=	SSPLv1 APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	only supported on amd64, aarch64, and powerpc64le; i386 deprecated in v3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${LOCALBASE}/bin/ar:devel/binutils
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libsnappy.so:archivers/snappy

USES=		compiler:c++14-lang cpe python:3.5+,build scons shebangfix
USE_RC_SUBR=	mongod

CONFLICTS_INSTALL=	mongodb36 mongodb4[24] mongodb50

SHEBANG_FILES=	src/mongo/installer/compass/install_compass
python_OLD_CMD=	@python_interpreter@

MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--use-system-pcre --use-system-snappy \
		--use-system-boost --use-system-zlib \
		--cxx-std=14 --libc++ \
		--runtime-hardening=on \
		--disable-warnings-as-errors \
		VERBOSE=on AR=${PREFIX}/bin/ar

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		SASL SSL
OPTIONS_DEFAULT=	SASL SSL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USES=	ssl
SSL_MAKE_ARGS=	--ssl

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == powerpc64le
EXTRA_PATCHES=	${FILESDIR}/${ARCH}
.endif

ALL_TARGET=	core

PORTSCOUT=	limitw:1,even

CPE_PRODUCT=	mongodb

pre-patch:
	${MV} ${WRKSRC}/src/third_party/wiredtiger/src/checksum/power8/crc32.sx ${WRKSRC}/src/third_party/wiredtiger/src/checksum/power8/crc32.S

post-install:
.for f in mongo mongod mongos
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${CP} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample

.include <bsd.port.mk>
