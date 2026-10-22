PKGNAMEPREFIX=	php80-

.if !defined(WITH_CLUSTER_ALLOW_TECHNICAL_DEBTS)
IGNORE=		PHP 8.0 is EOL; set WITH_CLUSTER_ALLOW_TECHNICAL_DEBTS=yes in make.conf to build it
.endif

BUILD_DEPENDS=	${LOCALBASE}/bin/phpize:lang/php80-legacy \
		autoconf>0:devel/autoconf
RUN_DEPENDS=	${LOCALBASE}/include/php/main/php.h:lang/php80-legacy

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-php-config=${LOCALBASE}/bin/php-config

PHP_EXT_DIR=	20200930
PHP_EXT_INI_FILE=	etc/php/ext-${PHP_MOD_PRIO}-${PHP_MODNAME}.ini.sample
PHP_HEADER_DIRS=	.
PHP_MOD_PRIO=	20
PHP_MODNAME=	${PORTNAME}

PLIST_SUB=	PHP_EXT_DIR=${PHP_EXT_DIR}

PHP_EXT_PKGMESSAGE=	${WRKDIR}/php-ext-pkg-message
_PKGMESSAGES+=	${PHP_EXT_PKGMESSAGE}

pre-configure:
	@${ECHO_MSG} "===>  PHPizing for ${PKGNAME}"
	@(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${LOCALBASE}/bin/phpize)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_LIB} ${WRKSRC}/modules/${PHP_MODNAME}.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
.for header in ${PHP_HEADER_DIRS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/${header}
	@${INSTALL_DATA} ${WRKSRC}/${header}/*.h \
		${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/${header}
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/config.h
	@${EGREP} "#define (COMPILE|HAVE|USE)_" ${WRKSRC}/config.h \
		> ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME}/config.h
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php
	@${ECHO_CMD} "extension=${PHP_MODNAME}.so" > ${STAGEDIR}${PREFIX}/${PHP_EXT_INI_FILE}

post-stage:
	@${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so" \
		>> ${TMPPLIST}
	@${FIND} -P ${STAGEDIR}${PREFIX}/include/php/ext/${PHP_MODNAME} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec echo \#include \\\"ext/${PHP_MODNAME}/config.h\\\" >> %D/include/php/ext/php_config.h" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@preunexec cp %D/include/php/ext/php_config.h %D/include/php/ext/php_config.h.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@preunexec grep -v ext/${PHP_MODNAME}/config.h %D/include/php/ext/php_config.h.orig > %D/include/php/ext/php_config.h || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@preunexec ${RM} %D/include/php/ext/php_config.h.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@sample ${PHP_EXT_INI_FILE}" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "[" > ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "{" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "  message: <<EOD" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "This file has been added to automatically load the installed extension:" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "${PREFIX}/${PHP_EXT_INI_FILE}" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "EOD" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "  type: install" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "}" >> ${PHP_EXT_PKGMESSAGE}
	@${ECHO_CMD} "]" >> ${PHP_EXT_PKGMESSAGE}
