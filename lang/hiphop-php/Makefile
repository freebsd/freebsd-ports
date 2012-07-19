# New ports collection makefile for:	hiphop
# Date created:				20120712
# Whom:					Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hiphop-php
PORTVERSION=	0.0.20120716
PORTREVISION=	2
CATEGORIES=	lang devel www
MASTER_SITES=	https://github.com/facebook/hiphop-php/tarball/${GITVERSION}/:main \
		http://unicode.org/Public/UNIDATA/:unidata \
		http://unicode.org/Public/MAPPINGS/ISO8859/:mappings
DIST_SUBDIR=	hiphop-php
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

PATCH_SITES=	http://cpp.in/dev/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Hiphop PHP to C++ code transformer

LICENSE=	PHP301 ZEND200 UNICODE
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	Unicode, Inc. License Agreement
LICENSE_NAME_ZEND200=	The Zend Engine License, version 2.00
LICENSE_FILE_PHP301=	${WRKSRC}/LICENSE.PHP
LICENSE_FILE_UNICODE=	${FILESDIR}/LICENSE.UNICODE
LICENSE_FILE_ZEND200=	${WRKSRC}/LICENSE.ZEND
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ZEND200=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_DISTFILES_PHP301=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
LICENSE_DISTFILES_UNICODE= EastAsianWidth.txt \
	8859-1.TXT 8859-2.TXT 8859-3.TXT 8859-4.TXT 8859-5.TXT \
	8859-6.TXT 8859-7.TXT 8859-8.TXT 8859-9.TXT 8859-10.TXT \
	8859-11.TXT 8859-13.TXT 8859-14.TXT 8859-15.TXT 8859-16.TXT
LICENSE_DISTFILES_ZEND200=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

LIB_DEPENDS=	icudata.48:${PORTSDIR}/devel/icu \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		tbb.4:${PORTSDIR}/devel/tbb \
		gd.4:${PORTSDIR}/graphics/gd \
		mcrypt.8:${PORTSDIR}/security/libmcrypt \
		onig.1:${PORTSDIR}/devel/oniguruma4 \
		pcre.1:${PORTSDIR}/devel/pcre \
		expat.6:${PORTSDIR}/textproc/expat2 \
		memcached.10:${PORTSDIR}/databases/libmemcached \
		c-client4.9:${PORTSDIR}/mail/cclient

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS
NLS_DESC=	Depend on gettext (required if binutils have NLS)

_EXTDIR=	share/hiphop-php/ext

BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison \
		flex:${PORTSDIR}/textproc/flex \
		re2c:${PORTSDIR}/devel/re2c \
		${LOCALBASE}/${_EXTDIR}/lib/libevent.a:${PORTSDIR}/devel/libevent-hiphop \
		${LOCALBASE}/${_EXTDIR}/lib/libcurl.a:${PORTSDIR}/ftp/curl-hiphop

RUN_DEPENDS+=	${LOCALBASE}/${_EXTDIR}/lib/libevent.a:${PORTSDIR}/devel/libevent-hiphop \
		${LOCALBASE}/${_EXTDIR}/lib/libcurl.a:${PORTSDIR}/ftp/curl-hiphop

WRKSRC=		${WRKDIR}/facebook-hiphop-php-${GITVERSION}
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
USE_CMAKE=	yes
USE_MYSQL=	yes
USE_GNOME=	libxml2
USE_OPENSSL=	yes
USE_OPENLDAP=	yes
USE_GETTEXT=	yes
USE_GCC=	4.4+

GITVERSION=	96532ec
FETCH_ARGS=	-pRr

CUSTOM_ENV=	HPHP_HOME=${WRKSRC} \
		HPHP_LIB=${WRKSRC}/bin \
		CMAKE_PREFIX_PATH=${WRKDIR}/libs

DISTFILES+=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:main \
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

PATCHFILES+=	hphp-freebsd-20120214.patch \
		hphp-libmemcached-1.0.patch

SUB_LIST+=	CC="${CC}" \
		CPP="${CPP}" \
		CXX="${CXX}" \
		HPHP_HOME="${DATADIR}" \
		HPHP="${DATADIR}/bin/hphp"

SUB_FILES+=	hphp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gettext
.endif

.include <bsd.port.pre.mk>

_CFLAGS=	-rpath=${LOCALBASE}/lib/${_GCC_BUILD_DEPENDS} \
		${CFLAGS}
_CXXFLAGS=	-rpath=${LOCALBASE}/lib/${_GCC_BUILD_DEPENDS} \
		${CXXFLAGS}
_LDFLAGS=	-rpath=${LOCALBASE}/lib/${_GCC_BUILD_DEPENDS} \
		${LDFLAGS}

CONFIGURE_ENV+=	${CUSTOM_ENV}
MAKE_ENV+=	${CUSTOM_ENV}

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/EastAsianWidth.txt \
		${WRKSRC}/src/third_party/libmbfl/mbfl/
.for i in 1 2 3 4 5 6 7 8 9 10 11 13 14 15 16
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/8859-${i}.TXT \
		${WRKSRC}/src/third_party/libmbfl/filters/
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|-levent|${WRKSRC}/libs/lib/libevent.a|g' \
		${WRKSRC}/src/third_party/libafdt/configure
	@${REINPLACE_CMD} -e 's|-L$$(LIB_DIR)|${_LDFLAGS} -L$$(LIB_DIR)|g' \
		${WRKSRC}/src/rules.mk
	@${REINPLACE_CMD} \
		-e 's|%%CURL_LIB%%|${LOCALBASE}/${_EXTDIR}/lib/libcurl.a|g' \
		-e 's|%%LIBEVENT_LIB%%|${LOCALBASE}/${_EXTDIR}/lib/libevent.a|g' \
		-e 's|%%CURL_INCLUDE_DIR%%|${LOCALBASE}/${_EXTDIR}/include|g' \
		-e 's|%%LIBEVENT_INCLUDE_DIR%%|${LOCALBASE}/${_EXTDIR}/include|g' \
		${WRKSRC}/CMake/HPHPFindLibs.cmake
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${_CFLAGS}|g' \
		-e 's|%%CXXFLAGS%%|${_CXXFLAGS}|g' \
		${WRKSRC}/CMake/HPHPSetup.cmake
	@${REINPLACE_CMD} -e 's|LICENSE.PHP|src/version|g' \
		${WRKSRC}/bin/CMakeLists.base.txt

do-install:
	@${MKDIR} ${DATADIR}/bin ${DATADIR}/src
	@${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} {} \;
	@${FIND} ${WRKSRC} -type f -name '*.bak' -exec ${RM} {} \;
	@${CP} -R ${WRKSRC}/CMake ${WRKSRC}/bin ${DATADIR}
	@${CP} -R ${WRKSRC}/src/runtime ${WRKSRC}/src/system \
		${WRKSRC}/src/util  ${DATADIR}/src
	@${INSTALL_DATA} ${WRKSRC}/src/version ${DATADIR}/src/version
	@${INSTALL_PROGRAM} ${WRKSRC}/src/hphp/hphp ${DATADIR}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/src/hphpi/hphpi ${PREFIX}/bin/hphpi
	@${INSTALL_SCRIPT} ${WRKDIR}/hphp ${PREFIX}/bin/hphp

.include <bsd.port.post.mk>
