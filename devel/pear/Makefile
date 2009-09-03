# New ports collection makefile for:	pear
# Date created:			25 Nov 2005
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pear
PORTVERSION=	1.9.0
CATEGORIES=	devel
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR framework for PHP

USE_BZIP2=	yes
NO_BUILD=	yes

WANT_PHP_CLI=	yes
USE_PHP=	pcre xml

PEARDIR=	${PREFIX}/share/pear

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/go-pear

do-install:
	@${LOCALBASE}/bin/php -q ${WRKSRC}/go-pear
	@${SED} -i "" "s|<?php|<?php dl('pcre.so'); dl('xml.so');|" \
		${PEARDIR}/peclcmd.php

.include <bsd.port.mk>
