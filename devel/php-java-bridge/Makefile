# New ports collection makefile for:	php-java-bridge
# Date created:			2008/06/04
# Whom:				chinsan
#
# $FreeBSD$
#

PORTNAME=	php-java-bridge
PORTVERSION=	5.2.2
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PHP module wich connects the PHP object with the Java/ECMA 335 object

USE_AUTOTOOLS=	autoconf:261:env automake:19:env libtool:15:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
#CONFIGURE_ARGS+=--prefix=${PREFIX} \
#		--disable-backend \
#		--disable-servlet \
#		--with-jdk-home="${JAVA_HOME}"
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
	${INSTALL_DATA} ${WRKSRC}/modules/RunJavaBridge \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/libnatcJavaBridge.a \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/libnatcJavaBridge.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
	${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/JavaBridge.jar" \
		>> ${TMPPLIST}
	${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/RunJavaBridge" \
		>> ${TMPPLIST}
	${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/libnatcJavaBridge.a" \
		>> ${TMPPLIST}
	${ECHO_CMD} "lib/php/${PHP_EXT_DIR}/libnatcJavaBridge.so" \
	 	>> ${TMPPLIST}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && ${OSVERSION} >= 700000
BROKEN=		does not install
.endif

.include <bsd.port.post.mk>
