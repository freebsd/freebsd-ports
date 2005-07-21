# New ports collection makefile for:	ZendOptimizer
# Date created:			Thu Apr 24 00:23:22 CET 2003
# Whom:				Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	ZendOptimizer
PORTVERSION=	2.5.10a
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd${VER}-i386

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An optimizer for PHP code

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
USE_PHP=	yes

RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

# Check for FreeBSD version
.if ${OSVERSION} < 400000
IGNORE=		This port is for FreeBSD 4 or above
.else
.if ${OSVERSION} < 500000
VER=		4.3
.else
VER=		5.1
.endif
# Check for ZendOptimizer sources
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.\n\
Please access http://www.zend.com/store/free_download.php?pid=13\n\
with a web browser, read the license and click the \"I ACCEPT\" button.\n\
Download the source file, ${DISTNAME}${EXTRACT_SUFX},\n\
and place it in ${DISTDIR}.\n
.endif
.endif

.if ${PHP_VER} == 4
ZEND_PATH=	4.4.x
.else
ZEND_PATH=	5.0.x
.endif

PLIST_SUB+=	ZEND_PATH=${ZEND_PATH}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}/Optimizer/php-${ZEND_PATH}
	${INSTALL_DATA} ${WRKSRC}/data/${ZEND_PATH:S/./_/g}_comp/ZendOptimizer.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}/Optimizer/php-${ZEND_PATH}/ZendOptimizer.so
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}/Optimizer_TS/php-${ZEND_PATH}
	${INSTALL_DATA} ${WRKSRC}/data/${ZEND_PATH:S/./_/g}_comp/TS/ZendOptimizer.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}/Optimizer_TS/php-${ZEND_PATH}/ZendOptimizer.so
	${INSTALL_DATA} ${WRKSRC}/data/ZendExtensionManager.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/data/ZendExtensionManager_TS.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/data/doc/* ${DOCSDIR}
.endif

post-install:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g;s|%%PHP_EXT_DIR%%|${PHP_EXT_DIR}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
