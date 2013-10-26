# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hiphop-php
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	lang devel www
MASTER_SITES=	https://github.com/facebook/hiphop-php/archive/:main \
		http://unicode.org/Public/UNIDATA/:unidata \
		http://unicode.org/Public/MAPPINGS/ISO8859/:mappings
DISTNAME=	HPHP-${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://cpp.in/dev/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	HipHop Virtual Machine for PHP (HHVM)

LICENSE=	PHP301 ZEND200 UNICODE
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	Unicode, Inc. License Agreement
LICENSE_NAME_ZEND200=	The Zend Engine License, version 2.00
LICENSE_FILE_PHP301=	${WRKSRC}/LICENSE.PHP
LICENSE_FILE_UNICODE=	${FILESDIR}/LICENSE.UNICODE
LICENSE_FILE_ZEND200=	${WRKSRC}/LICENSE.ZEND
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ZEND200=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_DISTFILES_PHP301=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_UNICODE= EastAsianWidth.txt \
	8859-1.TXT 8859-2.TXT 8859-3.TXT 8859-4.TXT 8859-5.TXT \
	8859-6.TXT 8859-7.TXT 8859-8.TXT 8859-9.TXT 8859-10.TXT \
	8859-11.TXT 8859-13.TXT 8859-14.TXT 8859-15.TXT 8859-16.TXT
LICENSE_DISTFILES_ZEND200=	${DISTNAME}${EXTRACT_SUFX}

LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		tbb:${PORTSDIR}/devel/tbb \
		gd:${PORTSDIR}/graphics/gd \
		mcrypt:${PORTSDIR}/security/libmcrypt \
		onig:${PORTSDIR}/devel/oniguruma4 \
		pcre:${PORTSDIR}/devel/pcre \
		expat:${PORTSDIR}/textproc/expat2 \
		memcached:${PORTSDIR}/databases/libmemcached \
		c-client4:${PORTSDIR}/mail/cclient \
		unwind:${PORTSDIR}/devel/libunwind \
		glog:${PORTSDIR}/devel/glog

OPTIONS_DEFINE=		DEBUG DOCS
OPTIONS_DEFAULT=	DOCS

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	This program is developed for amd64 only

_EXTDIR=	share/hiphop-php/ext

BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison \
		flex:${PORTSDIR}/textproc/flex \
		re2c:${PORTSDIR}/devel/re2c \
		bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/${_EXTDIR}/lib/libevent.a:${PORTSDIR}/devel/libevent-hiphop \
		${LOCALBASE}/${_EXTDIR}/lib/libcurl.a:${PORTSDIR}/ftp/curl-hiphop \
		${LOCALBASE}/lib/libdwarf.a:${PORTSDIR}/devel/libdwarf

WRKSRC=		${WRKDIR}/hiphop-php-HPHP-${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		cmake gettext
USE_MYSQL=	yes
USE_GNOME=	libxml2
USE_OPENSSL=	yes
USE_OPENLDAP=	yes
USE_GCC=	yes

GITVERSION=	96532ec
FETCH_ARGS=	-pRr

CUSTOM_ENV=	HPHP_HOME=${WRKSRC} \
		HPHP_LIB=${WRKSRC}/bin \
		CMAKE_PREFIX_PATH=${WRKDIR}/libs

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}:main \
		EastAsianWidth.txt:unidata \
		8859-1.TXT:mappings \
		8859-2.TXT:mappings \
		8859-3.TXT:mappings \
		8859-4.TXT:mappings \
		8859-5.TXT:mappings \
		8859-6.TXT:mappings \
		8859-7.TXT:mappings \
		8859-8.TXT:mappings \
		8859-9.TXT:mappings \
		8859-10.TXT:mappings \
		8859-11.TXT:mappings \
		8859-13.TXT:mappings \
		8859-14.TXT:mappings \
		8859-15.TXT:mappings \
		8859-16.TXT:mappings

PLIST_FILES=	bin/hhvm
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_BUILD_TYPE=	Debug
CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
.endif

.include <bsd.port.pre.mk>

_CFLAGS=	${CFLAGS} -DHAVE_POSIX_FALLOCATE=1
_CXXFLAGS=	${CXXFLAGS} -D_GLIBCXX_USE_C99 -DHAVE_POSIX_FALLOCATE=1

CONFIGURE_ENV+=	${CUSTOM_ENV}
MAKE_ENV+=	${CUSTOM_ENV}

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/EastAsianWidth.txt \
		${WRKSRC}/hphp/third_party/libmbfl/mbfl/
.for i in 1 2 3 4 5 6 7 8 9 10 11 13 14 15 16
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/8859-${i}.TXT \
		${WRKSRC}/hphp/third_party/libmbfl/filters/
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|-levent|${WRKSRC}/libs/lib/libevent.a|g' \
		${WRKSRC}/hphp/third_party/libafdt/configure
	@${REINPLACE_CMD} -e 's,#!/bin/bash,#!${LOCALBASE}/bin/bash,g' \
		${WRKSRC}/hphp/util/parser/test/run_verify_parse.sh \
		${WRKSRC}/hphp/util/generate_buildinfo.sh \
		${WRKSRC}/hphp/tools/timeout.sh
	@${REINPLACE_CMD} \
		-e 's|%%CURL_LIB%%|${LOCALBASE}/${_EXTDIR}/lib/libcurl.a /usr/lib/libgssapi.a|g' \
		-e 's|%%LIBEVENT_LIB%%|${LOCALBASE}/${_EXTDIR}/lib/libevent.a|g' \
		-e 's|%%CURL_INCLUDE_DIR%%|${LOCALBASE}/${_EXTDIR}/include|g' \
		-e 's|%%LIBEVENT_INCLUDE_DIR%%|${LOCALBASE}/${_EXTDIR}/include|g' \
		${WRKSRC}/CMake/HPHPFindLibs.cmake
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/CMake/FindLibDwarf.cmake \
		${WRKSRC}/CMake/FindLibElf.cmake
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${_CFLAGS}|g' \
		-e 's|%%CXXFLAGS%%|${_CXXFLAGS}|g' \
		${WRKSRC}/CMake/HPHPSetup.cmake
	@${REINPLACE_CMD} -e 's|../src/hhvm/hhvm|hhvm|g' \
		${WRKSRC}/hphp/doc/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hphp/hhvm/hhvm ${LOCALBASE}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${CP} -rf ${WRKSRC}/hphp/doc/ ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
