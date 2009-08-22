# New ports collection makefile for:	php-java-bridge
# Date created:			2008/06/04
# Whom:				chinsan
#
# $FreeBSD$
#

PORTNAME=	php-java-bridge
PORTVERSION=	5.4.3
CATEGORIES=	devel java
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PHP module wich connects the PHP object with the Java/ECMA 335 object

USE_AUTOTOOLS=	autoconf:262:env automake:19:env libtool:22:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_BUILD=	jdk

USE_PHP=	session
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	java

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-configure:
	(cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${PHPBASE}/bin/phpize)
	(cd ${WRKSRC}; ./configure --with-java="${JAVA_HOME}")

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/JavaBridge.jar \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/modules/RunJavaBridge \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/modules/libnatcJavaBridge.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
	${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/JavaBridge.jar" \
		>> ${TMPPLIST}
	${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/RunJavaBridge" \
		>> ${TMPPLIST}
	${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/libnatcJavaBridge.so" \
	 	>> ${TMPPLIST}

.include <bsd.port.mk>
