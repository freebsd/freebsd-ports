# Ports collection makefile for:  pear-sqlite
# Date created:			  2004-04-30
# Whom:				  mat
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	1.0.2
CATEGORIES=	databases www pear

MAINTAINER=	mat@FreeBSD.org
COMMENT=	PEAR classes to access sqlite databases

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/SQLite-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_PHP=	yes
USE_PHPIZE=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

.if exists(${LOCALBASE}/bin/php-config)
EXT_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e \
			"s:${PHP_BASE}/::"
.endif
PHP_DIR?=	${LOCALBASE}/etc
PHP_INI=	${PHP_DIR}/php.ini
PLIST_SUB+=	EXTDIR=${EXT_DIR}

DOCSDIR=	${PEARDIR}/docs/${PORTNAME}
DOCS=		CREDITS README
TESTDIR=	${PEARDIR}/tests/${PORTNAME}

post-install-script:
	@${STRIP_CMD} ${PHP_BASE}/${EXT_DIR}/sqlite.so
# Configure extension_dir
	@if [ ! -f ${PHP_INI} ]; then \
		${ECHO_MSG} "===>   Creating ${PHP_INI} for PHP" ; \
		${CP} -p ${PHP_INI}-dist ${PHP_INI} ; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${TESTDIR}
	@${CP} -Rp ${WRKSRC}/tests/* ${TESTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TESTDIR}
	@${ECHO_MSG} "===> Examples installed in ${TESTDIR}."
.endif
	@${ECHO_MSG}
	@${SED} -e "s:%%INI%%:${PHP_INI}:"	\
		-e "s:%%BASE%%:${PHP_BASE}/${EXT_DIR}:" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
