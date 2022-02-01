PORTNAME=	php74
DISTVERSION=	7.4.27
PORTREVISION?=	0
CATEGORIES?=	lang devel www
MASTER_SITES=	PHP
DISTNAME=	php-${DISTVERSION}
DIST_SUBDIR=	php

MAINTAINER=	tz@FreeBSD.org
COMMENT=	PHP Scripting Language

LICENSE=	PHP301

DEPRECATED=Upstream Security Support ends on 2022-11-28
EXPIRATION_DATE=2022-11-29

USES+=		compiler:c11 tar:xz cpe gnome pkgconfig
CPE_PRODUCT=	php
NO_OPTIONS_SORT=yes

.if !defined(PKGNAMESUFFIX)
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libargon2.so:security/libargon2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-layout=GNU \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--disable-all \
		--with-libxml \
		--with-password-argon2=${LOCALBASE} \
		--program-prefix=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
USES+=		autoreconf:build
USE_GNOME=	libxml2

# PR230207 Allow relocations against read-only segments (override lld default)
LDFLAGS_i386=	-Wl,-z,notext

CONFLICTS_INSTALL=	php[0-9][0-9]${PKGNAMESUFFIX}

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
OPTIONS_EXCLUDE_powerpc64=	${OPTIONS_EXCLUDE_${ARCH}_${OSREL:R}}
OPTIONS_EXCLUDE_powerpc64_11=	DTRACE
OPTIONS_EXCLUDE_powerpc64_12=	DTRACE
OPTIONS_EXCLUDE_riscv64=	DTRACE
OPTIONS_EXCLUDE_sparc64=	DTRACE
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
ZTS_CONFIGURE_ENV=	pthreads_working="yes"
ZTS_CONFIGURE_ON=--enable-maintainer-zts

DESTDIRNAME=	INSTALL_ROOT

.include <bsd.port.pre.mk>

.if ${ARCH} == riscv64
CONFIGURE_ARGS+=--without-pcre-jit
.endif

.if defined(PKGNAMEPREFIX)
USES+=		apache:2.2+
.include "${PORTSDIR}/Mk/Uses/apache.mk"
.if ${PORT_OPTIONS:MAP2FILTER}
CONFIGURE_ARGS+=--with-apxs2filter=${APXS}
.else
CONFIGURE_ARGS+=--with-apxs2=${APXS}
.endif
PLIST=		${PKGDIR}/pkg-plist.mod
PKGMESSAGE=	${PKGDIR}/pkg-message.mod
MODULENAME=	libphp7
SHORTMODNAME=	php7
WARNING=	"!!! If you have a threaded Apache, you must build ${PHP_PORT} with ZTS support to enable thread-safety in extensions !!!"
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
		lt_cv_path_SED="sed"

post-patch:
	@${TOUCH} ${WRKSRC}/ext/php_config.h
	@${REINPLACE_CMD} "s|^\(extension_dir\)|; \1|" ${WRKSRC}/php.ini-*

post-patch-FPM-on:
	@${REINPLACE_CMD} -e "s|^;\(pid\)|\1|;s|^;\(pm\.[a-z_]*_servers\)|\1|" \
		${WRKSRC}/sapi/fpm/php-fpm.conf.in

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} MAKE=${MAKE_CMD} ./buildconf --force)

.if !defined(PKGNAMEPREFIX)
post-build:
	@${ECHO_CMD} "PHP_VER=74" > ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_VERSION=${PORTVERSION}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_SAPI=${PHP_SAPI}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_EXT_INC=hash pcre spl" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} -n "PHP_EXT_DIR=" >> ${WRKDIR}/php.conf
	@${SH} ${WRKSRC}/scripts/php-config --extension-dir | ${SED} -ne 's,^${PREFIX}/lib/php/,,p' >> ${WRKDIR}/php.conf

test: build
	@(cd ${WRKSRC} && ${MAKE} test)

post-install:
	${INSTALL_DATA} ${WRKSRC}/php.ini-development ${WRKSRC}/php.ini-production \
		${WRKDIR}/php.conf ${STAGEDIR}/${PREFIX}/etc
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
