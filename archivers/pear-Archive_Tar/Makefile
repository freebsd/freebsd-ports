# Ports collection makefile for:  pear-Archive_Tar
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Archive_Tar
PORTVERSION=	1.0
CATEGORIES=	archivers www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR tar file management class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php.dist:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_BASE=	${LOCALBASE}
.endif

LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

DOCSDIR=	${PEARDIR}/docs/Archive_Tar

do-install:
	@${MV} ${PEARDIR}/Archive ${PEARDIR}/Archive.dist
	@${CP} -Rp ${WRKSRC}/Archive ${PEARDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Archive
.if !defined(NOPORTDOCS)
	@${MV} ${DOCSDIR} ${DOCSDIR}.dist
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/Archive_Tar.txt ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
