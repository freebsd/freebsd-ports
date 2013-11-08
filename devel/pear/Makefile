# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pear
PORTVERSION=	1.9.4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://miwibox.org/distfiles/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR framework for PHP

USE_BZIP2=	yes
NO_BUILD=	yes

WANT_PHP_CLI=	yes
USE_PHP=	pcre xml
USE_PHP_BUILD=	yes

PEARDIR=	${PREFIX}/share/pear

# https://github.com/pear/pear-core/blob/master/install-pear.php
# supports ${SETENV} INSTALL_ROOT=${STAGEDIR}
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%BUNDLEDIR%%|${WRKSRC}/go-pear-bundle|" \
		-e "s|%%TMPDIR%%|/tmp/pear|" \
		${WRKSRC}/go-pear
	@cd ${WRKSRC}/go-pear-bundle && ${MKDIR} tmp && ${TAR} -C tmp -xf PEAR-${PORTVERSION}.tar
	@cd ${WRKSRC}/go-pear-bundle/tmp/PEAR-${PORTVERSION} && ${PATCH} -s -p0 < ${FILESDIR}/extra-patch-PEAR-Config.php
	@${RM} ${WRKSRC}/go-pear-bundle/tmp/PEAR-${PORTVERSION}/PEAR/Config.php.orig
	@${MD5} -q ${WRKSRC}/go-pear-bundle/tmp/PEAR-${PORTVERSION}/PEAR/Config.php > ${WRKSRC}/Config.php.md5
	@${REINPLACE_CMD} -E -e "s|(file md5sum=\").*(\" name=\"PEAR/Config.php\" role=\"php\")|\1`${CAT} ${WRKSRC}/Config.php.md5`\2|g" \
		${WRKSRC}/go-pear-bundle/tmp/package2.xml ${WRKSRC}/go-pear-bundle/package2.xml
	@cd ${WRKSRC}/go-pear-bundle/tmp && ${TAR} -cf ../PEAR-${PORTVERSION}.tar package2.xml PEAR-${PORTVERSION} package.xml

do-install:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/php -q ./go-pear
	@${SED} -i "" "s|<?php|<?php dl('pcre.so'); dl('xml.so');|" \
		${PEARDIR}/peclcmd.php

post-install:
	@${CP} -n ${PREFIX}/etc/pear.conf.sample ${PREFIX}/etc/pear.conf || ${TRUE}

.include <bsd.port.mk>
