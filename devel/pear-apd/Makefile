# Ports collection makefile for:  pear-apd
# Date created:			  06 Septemeber 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	apd
PORTVERSION=	1.0.1
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-featured engine-level PHP profiler/debugger

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes
USE_PHPIZE=	yes
DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4

IGNORE=	"cannot build package if pear-* have been built with PHP4"

CONFIGURE_ARGS=	--enable-apd

DUMP_DIR?=	/var/tmp/apd

PORTDOCS=	README

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

PLIST_SUB+=	EXTDIR=lib/php/${PHP_EXT_DIR}

SUB_FILES=	pkg-message
SUB_LIST=	PHP_EXT_DIR=${PHP_EXT_DIR} DUMP_DIR=${DUMP_DIR}

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

post-install-script:
	@${STRIP_CMD} ${PHP_BASE}/lib/php/${PHP_EXT_DIR}/apd.so
	@${MKDIR} ${DUMP_DIR}
	@${CHMOD} a+w ${DUMP_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/pprofp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
