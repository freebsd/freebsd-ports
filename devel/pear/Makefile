# Ports collection makefile for:  pear
# Date created:			  Sat Nov 10, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	pear
PORTVERSION=	${PHP_VERSION}
CATEGORIES=	devel www
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	thierry@pompo.net

BUILD_DEPENDS=	${LOCALBASE}/bin/php-config:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${PEARDIR}/PEAR.php.dist:${PORTSDIR}/devel/pear-PEAR	\
		${PEARDIR}/Console/Getopt.php.dist:${PORTSDIR}/devel/pear-Console_Getopt	\
		${PEARDIR}/File.php:${PORTSDIR}/sysutils/pear-File	\
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log	\
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime	\
		${PEARDIR}/Net/Sieve.php:${PORTSDIR}/net/pear-Net_Sieve

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_VERSION!=	${LOCALBASE}/bin/php-config --version
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_VERSION=	4.2.3
PHP_BASE=	${LOCALBASE}
.endif
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}

do-install:	# empty
	${DO_NADA}

.include <bsd.port.post.mk>
