# Ports collection makefile for:  pear
# Date created:			  Sat Nov 10, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	pear
PORTVERSION=	${PHP_VERSION:C/RC.//}
CATEGORIES=	devel www pear
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	thierry@pompo.net
COMMENT=	A framework and distribution system for reusable PHP components

BUILD_DEPENDS=	${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php4
RUN_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB		\
		${PEARDIR}/File.php:${PORTSDIR}/sysutils/pear-File	\
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log	\
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_VERSION!=	${LOCALBASE}/bin/php-config --version
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_VERSION=	4.3.2
PHP_BASE=	${LOCALBASE}
.endif
PEARDIR=	${PHP_BASE}/share/pear

do-install:	# empty
	${DO_NADA}

.include <bsd.port.post.mk>
