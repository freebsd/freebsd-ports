# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php70
PORTVERSION=	7.0.26
PORTREVISION?=	0
CATEGORIES?=	lang devel www
MASTER_SITES=	PHP/distributions
DISTNAME=	php-${PORTVERSION}

MAINTAINER=	tz@FreeBSD.org
COMMENT=	PHP Scripting Language

LICENSE=	PHP301

USES+=		tar:xz cpe
CPE_PRODUCT=	php
NO_OPTIONS_SORT=yes
.if !defined(PKGNAMESUFFIX)
USE_AUTOTOOLS=	autoconf
#NOTE: libtools ends with Version mismatch error
#USES+=		autoreconf gmake
#GNU_CONFIGURE=	yes

LIB_DEPENDS=	libpcre.so:devel/pcre

CONFIGURE_ARGS+=--with-layout=GNU \
		--localstatedir=/var \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--disable-all \
		--enable-libxml \
		--enable-mysqlnd \
		--with-libxml-dir=${LOCALBASE} \
		--with-pcre-regex=${LOCALBASE} \
		--program-prefix=""

USE_GNOME=	libxml2

OPTIONS_DEFINE+=CLI CGI FPM EMBED PHPDBG DEBUG DTRACE IPV6 MAILHEAD LINKTHR ZTS
OPTIONS_DEFAULT=CLI CGI FPM LINKTHR DTRACE
# Bug 197128:  No ASM code for MIPS/MIPS64, disable FPM
OPTIONS_EXCLUDE_mips=FPM
OPTIONS_EXCLUDE_mips64=FPM
OPTIONS_SUB=	yes

OPTIONS_EXCLUDE_DragonFly=	DTRACE
# ld(1) fails to link probes: Relocations in generic ELF (EM: 0)
OPTIONS_EXCLUDE_aarch64=	DTRACE
OPTIONS_EXCLUDE_sparc64=	DTRACE

CLI_DESC=	Build CLI version
CGI_DESC=	Build CGI version
FPM_DESC=	Build FPM version
EMBED_DESC=	Build embedded library
PHPDBG_DESC=	Interactive PHP debugger
MAILHEAD_DESC=	Enable mail header patch
LINKTHR_DESC=	Link thread lib (for threaded extensions)
ZTS_DESC=	Force Zend Thread Safety (ZTS) build

CONFLICTS=	php56-* php71-* php72-*

DESTDIRNAME=	INSTALL_ROOT

.include <bsd.port.pre.mk>

PATCH_DIST_STRIP=	-p1

.if ${PORT_OPTIONS:MMAILHEAD}
PATCHFILES+=	php-7.0.x-mail-header.patch:mail
PATCH_SITES+=	http://choon.net/opensource/php/:mail
.endif

.if ${PORT_OPTIONS:MCLI}
PHP_SAPI+=	cli
.else
CONFIGURE_ARGS+=--disable-cli
.endif

.if ${PORT_OPTIONS:MCGI}
PHP_SAPI+=	cgi
.else
CONFIGURE_ARGS+=--disable-cgi
.endif

.if ${PORT_OPTIONS:MFPM}
PHP_SAPI+=	fpm
USE_RC_SUBR+=	php-fpm
CONFIGURE_ARGS+=--enable-fpm \
		--with-fpm-user=${WWWOWN} \
		--with-fpm-group=${WWWGRP}
.endif

.if defined(PKGNAMEPREFIX)
USE_APACHE=	22+
.include "${PORTSDIR}/Mk/bsd.apache.mk"
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

.if ${PORT_OPTIONS:MEMBED}
PHP_SAPI+=	embed
CONFIGURE_ARGS+=--enable-embed
.endif

.if ${PORT_OPTIONS:MPHPDBG}
PHP_SAPI+=	phpdbg
CONFIGURE_ARGS+=--enable-phpdbg
.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-phpdbg-debug
.endif
.endif

.if ${PORT_OPTIONS:MCLI} || ${PORT_OPTIONS:MEMBED}
PLIST_SUB+=	SAPI_INC=""
.else
PLIST_SUB+=	SAPI_INC="@comment "
.endif

CONFIGURE_ENV+=	ac_cv_decimal_fp_supported="no" \
		lt_cv_path_SED="sed"

.if ${PORT_OPTIONS:MLINKTHR}
LIBS+=		-lpthread
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MZTS}
CONFIGURE_ARGS+=--enable-maintainer-zts
CONFIGURE_ENV+=	pthreads_working="yes"
.endif

.if ${PORT_OPTIONS:MDTRACE}
CONFIGURE_ARGS+=--enable-dtrace
PLIST_SUB+=	DTRACE=""
.else
PLIST_SUB+=	DTRACE="@comment "
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/ext/php_config.h
	@${REINPLACE_CMD} "s|^\(extension_dir\)|; \1|" ${WRKSRC}/php.ini-*
.if ${PORT_OPTIONS:MFPM}
	@${REINPLACE_CMD} -e "s|^;\(pid\)|\1|;s|^;\(pm\.[a-z_]*_servers\)|\1|" \
		${WRKSRC}/sapi/fpm/php-fpm.conf.in
.endif

# Work around issues with newer (>=2.64) autoconf
pre-configure:
	@${REINPLACE_CMD} -E 's:^((m4_)?divert)[(]([0-9]*)[)]:\1(600\3):' \
		${WRKSRC}/configure.in `${FIND} ${WRKSRC} -name '*.m4'`
	@${RM} ${WRKSRC}/configure
	@${CAT} ${WRKSRC}/acinclude.m4 ${WRKSRC}/build/libtool.m4 > ${WRKSRC}/aclocal.m4

.if !defined(PKGNAMEPREFIX)
post-build:
	@${ECHO_CMD} "PHP_VER=70" > ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_VERSION=${PORTVERSION}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_SAPI=${PHP_SAPI}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_EXT_INC=pcre spl" >> ${WRKDIR}/php.conf
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
