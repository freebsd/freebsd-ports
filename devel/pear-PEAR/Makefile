# Ports collection makefile for:  pear-PEAR
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	PEAR
PORTVERSION=	1.0.1
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1/b1/}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install
RUN_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.endif
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

do-install:
	@${MV} ${PEARDIR}/PEAR ${PEARDIR}/PEAR.dist
	@${MV} ${PEARDIR}/PEAR.php ${PEARDIR}/PEAR.php.dist
	@${MV} ${PEARDIR}/System.php ${PEARDIR}/System.php.dist
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}
	@${CHOWN} -R root:wheel ${PEARDIR}/OS
	@${CHOWN} -R root:wheel ${PEARDIR}/PEAR*
	@${CHOWN} -R root:wheel ${PEARDIR}/System.php
	@${CHOWN} -R root:wheel ${PEARDIR}/package.dtd
	@${CHOWN} -R root:wheel ${PEARDIR}/scripts
	@${CHOWN} -R root:wheel ${PEARDIR}/template.spec

.include <bsd.port.post.mk>
