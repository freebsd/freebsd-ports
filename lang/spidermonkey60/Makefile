# $FreeBSD$

PORTNAME=	spidermonkey
DISTVERSION=	60.9.0
CATEGORIES=	lang
MASTER_SITES=	MOZILLA/firefox/releases/${DISTVERSION}esr/source
PKGNAMESUFFIX=	${SP_VER}
DISTNAME=	firefox-${DISTVERSION}esr.source

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Standalone JavaScript based from Mozilla 60-esr

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	autoconf-2.13:devel/autoconf213
LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libffi.so:devel/libffi \
		libicudata.so:devel/icu

HAS_CONFIGURE=	yes
USES=		compiler:c++14-lang gmake localbase pathfix pkgconfig \
		python:2.7,build tar:xz
USE_LDCONFIG=	yes
SP_VER=		60

WRKSRC=		${WRKDIR}/firefox-${DISTVERSION}
PATCH_WRKSRC=		${WRKDIR}/firefox-${DISTVERSION}/
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_SCRIPT=	../firefox-${DISTVERSION}/js/src/configure

CONFIGURE_ARGS=	--with-pthreads \
		--prefix=${PREFIX:Q} \
		--target=${CONFIGURE_TARGET} \
		--with-intl-api \
		--with-system-zlib \
		--disable-gold \
		--disable-debug \
		--disable-debug-symbols \
		--disable-jemalloc \
		--with-system-icu \
		--with-system-nspr \
		--enable-shared-js \
		--enable-optimize \
		--enable-readline

CONFIGURE_ENV=	HOST_CC=${CC} HOST_CXX=${CXX}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libjs_static.ajs
	${LN} -fs libmozjs-${SP_VER}.so ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/js${SP_VER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.*

.include <bsd.port.post.mk>
