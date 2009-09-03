# New ports collection makefile for:	php-chartdirector
# Date created:			29 Jul 2007
# Whom:				<swhetzel@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	chartdirector
PORTVERSION=	5.0.1
CATEGORIES?=	graphics
MASTER_SITES=	http://download.advsofteng.com/ \
		http://download2.advsofteng.com/
PKGNAMEPREFIX?=	php5-

MAINTAINER=	swhetzel@gmail.com
COMMENT=	ChartDirector Chart Component for PHP ${PHP_VER}

USE_PHP=	yes
NO_BUILD=	yes
ONLY_FOR_ARCH=	i386 amd64
SUB_FILES=	pkg-message
IGNORE_WITH_PHP?=4
DEFAULT_PHP_VER?=5
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/ChartDirector

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
DISTNAME=	chartdir_php_freebsd_64
.else
DISTNAME=	chartdir_php_freebsd
.endif

.if ${PHP_VER} == 5
PHP_CHARTDIR_DLL=	phpchartdir520.dll
PHP_CHARTDIR_MT_DLL=	phpchartdir520mt.dll
.else
PHP_CHARTDIR_DLL=	phpchartdir421.dll
PHP_CHARTDIR_MT_DLL=	phpchartdir421mt.dll
.endif
PLIST_SUB+=	PHP_CHARTDIR_DLL=${PHP_CHARTDIR_DLL} \
		PHP_CHARTDIR_MT_DLL=${PHP_CHARTDIR_MT_DLL}

PHP_CHARTDIRECTOR=	${PREFIX}/lib/php/${PHP_EXT_DIR}

.if !defined(NOPORTEXAMPLES)
post-patch:
	@(cd ${WRKSRC}/phpdemo ; \
	 for f in *.php ; do \
		${REINPLACE_CMD} -e 's@../lib/@${PHP_CHARTDIRECTOR}/@' $${f} ; \
	 done)
.endif

do-install:
	@${INSTALL} -d ${PHP_CHARTDIRECTOR}
	@${INSTALL} -d ${PHP_CHARTDIRECTOR}/fonts
	@(cd ${WRKSRC}/lib ; \
	 for f in *.so *.php ${PHP_CHARTDIR_DLL} ${PHP_CHARTDIR_MT_DLL} ; do \
		${INSTALL_SCRIPT} $${f} ${PHP_CHARTDIRECTOR}/ ; \
	 done)
	@(cd ${WRKSRC}/lib/fonts ; \
	 for f in * ; do \
		${INSTALL_DATA} $${f} ${PHP_CHARTDIRECTOR}/fonts/ ; \
	 done)
	@${INSTALL} -d ${PREFIX}/etc/php
	@${ECHO_CMD} extension=${PHP_CHARTDIR_DLL} \
		>> ${PREFIX}/etc/php/extensions.ini
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}
	@${INSTALL} -d ${DOCSDIR}/cdphpdoc
	@${INSTALL} -d ${DOCSDIR}/cdphpdoc/images
	@${INSTALL_DATA} ${WRKSRC}/doc/cdphp.htm ${DOCSDIR}
	@(cd ${WRKSRC}/doc/cdphpdoc ; \
	 for f in *.htm *.gif *.css ; do \
		${INSTALL_DATA} $${f} ${DOCSDIR}/cdphpdoc/ ; \
	 done)
	@(cd ${WRKSRC}/doc/cdphpdoc/images ; \
	 for f in * ; do \
		 ${INSTALL_DATA} $${f} ${DOCSDIR}/cdphpdoc/images/ ; \
	 done)
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@(cd ${WRKSRC}/phpdemo ; \
	 for f in *.cur *.gif *.js *.php *.png *.sql; do \
		${INSTALL_DATA} $${f} ${EXAMPLESDIR}/ ; \
	 done)
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

security-check: php-ini

php-ini:
	@${ECHO_CMD} "****************************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following line has been added to your ${PREFIX}/etc/php/extensions.ini"
	@${ECHO_CMD} "configuration-file to automatically load the installed extension:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "extension=${PHP_CHARTDIR_DLL}"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "****************************************************************************"

.include <bsd.port.post.mk>
