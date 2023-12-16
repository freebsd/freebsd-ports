PORTNAME=	php80
DISTVERSION=	8.0.30
CATEGORIES?=	lang devel www
MASTER_SITES=	PHP
DISTNAME=	php-${DISTVERSION}
DIST_SUBDIR=	php

MAINTAINER=	tz@FreeBSD.org
COMMENT=	PHP Scripting Language
WWW=		https://www.php.net/

LICENSE=	PHP301

DEPRECATED=	Upstream support ends on 2023-11-26
EXPIRATION_DATE=	2023-12-31

USES+=		compiler:c11 tar:xz cpe gnome localbase pkgconfig
CPE_PRODUCT=	php

CONFLICTS_INSTALL?=	php[0-9][0-9]${PKGNAMESUFFIX}

.if !defined(PKGNAMESUFFIX)
BUILD_DEPENDS=	re2c>0:devel/re2c
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libargon2.so:security/libargon2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
		--disable-all \
		--program-prefix="" \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--with-layout=GNU \
		--with-libxml \
		--with-openssl \
		--with-password-argon2=${LOCALBASE} \
		--with-external-pcre=${LOCALBASE}

USES+=		autoreconf:build ssl
USE_GNOME=	libxml2

LDFLAGS=	-L${OPENSSLLIB} -lcrypto -lssl
# PR230207 Allow relocations against read-only segments (override lld default)
LDFLAGS_i386=	-Wl,-z,notext

OPTIONS_DEFINE+=CLI CGI FPM EMBED PHPDBG DEBUG DTRACE IPV6 MYSQLND LINKTHR ZTS
OPTIONS_DEFAULT=CLI CGI FPM EMBED MYSQLND LINKTHR DTRACE
OPTIONS_EXCLUDE_DragonFly=	DTRACE
# ld(1) fails to link probes: Relocations in generic ELF (EM: 0)
OPTIONS_EXCLUDE_aarch64=	DTRACE
# dt_modtext:opensolaris/ib/libdtrace/common/dt_link.c: arm not impemented
OPTIONS_EXCLUDE_armv6=		DTRACE
OPTIONS_EXCLUDE_armv7=		DTRACE
# Bug 197128:  No ASM code for MIPS/MIPS64, disable FPM
OPTIONS_EXCLUDE_mips=		DTRACE FPM
OPTIONS_EXCLUDE_mips64=		DTRACE FPM
OPTIONS_EXCLUDE_powerpc64=		${OPTIONS_EXCLUDE_${ARCH}_${OSREL:R}}
OPTIONS_EXCLUDE_powerpc64_12=	DTRACE
OPTIONS_EXCLUDE_riscv64=	DTRACE
OPTIONS_EXCLUDE_sparc64=	DTRACE
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes

CGI_DESC=	Build CGI version
CLI_DESC=	Build CLI version
EMBED_DESC=	Build embedded library
FPM_DESC=	Build FPM version
LINKTHR_DESC=	Link thread lib (for threaded extensions)
MYSQLND_DESC=	Build with MySQL Native Driver
PHPDBG_DESC=	Interactive PHP debugger
ZTS_DESC=	Force Zend Thread Safety (ZTS) build

CGI_CONFIGURE_OFF=--disable-cgi
CGI_VARS=	PHP_SAPI+=cgi
CLI_CONFIGURE_OFF=--disable-cli
CLI_VARS=	PHP_SAPI+=cli
DEBUG_CONFIGURE_ON=--enable-debug
DTRACE_CONFIGURE_ON=--enable-dtrace
EMBED_CONFIGURE_ON=--enable-embed
EMBED_VARS=	PHP_SAPI+=embed
FPM_CONFIGURE_ON=--enable-fpm \
		--with-fpm-user=${WWWOWN} \
		--with-fpm-group=${WWWGRP}
FPM_VARS=	PHP_SAPI+=fpm USE_RC_SUBR+=php-fpm
IPV6_CONFIGURE_OFF=--disable-ipv6
LINKTHR_LIBS=		-lpthread
MYSQLND_CONFIGURE_ON=--enable-mysqlnd
PHPDBG_CONFIGURE_ON=--enable-phpdbg
PHPDBG_VARS=	PHP_SAPI+=phpdbg
ZTS_CONFIGURE_ON=--enable-zts
ZTS_CONFIGURE_ENV=	pthreads_working="yes"

DESTDIRNAME=	INSTALL_ROOT

.if defined(PKGNAMEPREFIX)
USES+=		apache
PLIST=		${PKGDIR}/pkg-plist.mod
PKGMESSAGE=	${PKGDIR}/pkg-message.mod
MODULENAME=	libphp
SHORTMODNAME=	php
WARNING=	"!!! If you have a threaded Apache, you must build ${PHP_PORT} with ZTS support to enable thread-safety in extensions !!!"
.endif

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl3*}
CXXFLAGS+=	-DOPENSSL_API_COMPAT=0x30000000L
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == riscv64
CONFIGURE_ARGS+=--without-pcre-jit
.endif

.if ${PORT_OPTIONS:MPHPDBG} && ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-phpdbg-debug
.endif

.if ${PORT_OPTIONS:MCLI} || ${PORT_OPTIONS:MEMBED}
PLIST_SUB+=	SAPI_INC=""
.else
PLIST_SUB+=	SAPI_INC="@comment "
.endif

CONFIGURE_ENV+=	ac_cv_decimal_fp_supported="no" \
		lt_cv_path_SED="sed" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" \
		PHP_OPENSSL=yes

post-patch:
	@${TOUCH} ${WRKSRC}/ext/php_config.h

post-patch-FPM-on:
	@${REINPLACE_CMD} -e "s|^;\(pid\)|\1|;s|^;\(pm\.[a-z_]*_servers\)|\1|" \
		${WRKSRC}/sapi/fpm/php-fpm.conf.in

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} MAKE=${MAKE_CMD} ./buildconf --force)

.if !defined(PKGNAMEPREFIX)
post-build:
	@${ECHO_CMD} "PHP_VER=80" > ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_VERSION=${PORTVERSION}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_SAPI=${PHP_SAPI}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} -n "PHP_EXT_DIR=" >> ${WRKDIR}/php.conf
	@${SH} ${WRKSRC}/scripts/php-config --extension-dir | ${SED} -ne 's,^${PREFIX}/lib/php/,,p' >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_EXT_INC=hash json openssl pcre spl" >> ${WRKDIR}/php.conf

test: build
	@(cd ${WRKSRC} && ${MAKE} test)

post-install:
	${INSTALL_DATA} ${WRKSRC}/php.ini-development ${WRKSRC}/php.ini-production \
		${WRKDIR}/php.conf ${STAGEDIR}/${PREFIX}/etc

post-install-CLI-on:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/php

post-install-CGI-on:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/php-cgi

post-install-EMBED-on:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/libphp.so

post-install-FPM-on:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/sbin/php-fpm

post-install-PHPDBG-on:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/phpdbg

.else
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_LIB} ${WRKSRC}/libs/${MODULENAME}.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}
.endif

.else
.include "${MASTERDIR}/Makefile.ext"
.endif
.include <bsd.port.post.mk>
