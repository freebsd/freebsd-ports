# Ports collection makefile for:  pear-apd
# Date created:			  06 Septemeber 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	apd
PORTVERSION=	0.4p2
CATEGORIES=	devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-featured engine-level PHP profiler/debugger

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--enable-apd

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

.if exists(${LOCALBASE}/bin/php-config)
EXT_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e \
			"s:${PHP_BASE}/::"
.endif
PHP_DIR?=	${LOCALBASE}/etc
DUMP_DIR?=	/var/tmp/apd
PHP_INI=	${PHP_DIR}/php.ini
PLIST_SUB+=	EXTDIR=${EXT_DIR}
DOCS=		README

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

post-install-script:
	@${STRIP_CMD} ${PHP_BASE}/${EXT_DIR}/apd.so
	@${MKDIR} ${DUMP_DIR}
	@${CHMOD} a+w ${DUMP_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/pprofp ${PREFIX}/bin
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
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
		${SED} -e "s:/usr/local/etc/php.ini:${PHP_INI}:"	\
			-e "s:/usr/local:${LOCALBASE}:"			\
			-e "s:lib/php/20020429:${EXT_DIR}:"		\
			-e "s:/var/tmp/apd:${DUMP_DIR}:"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
