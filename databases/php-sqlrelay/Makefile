# New ports collection makefile for:	PHP module for SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	# none
PKGNAMEPREFIX=	php-
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP modules to access to SQL Relay

EXTRACT_DEPENDS=	${NONEXISTENT}:${SQLRELAY_PORTDIR}:patch
LIB_DEPENDS=	sqlrclient.0:${SQLRELAY_PORTDIR}

USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src/api/php
INSTALL_WRKSRC=	${BUILD_WRKSRC}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREADINCLUDES="${PTHREAD_CFLAGS}" \
		PTHREADLIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--with-php-prefix="${LOCALBASE}"
USE_PHP=	yes
USE_PHP_BUILD=	yes

.include "${.CURDIR}/../sqlrelay/Makefile.common"

.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${SQLRELAY_WRKSRC_CMD}` ${WRKSRC}
	${RM} -f ${WRKSRC}/config.cache
	${CP} ${TEMPLATES}/config.sub ${WRKSRC}
	${CP} ${TEMPLATES}/config.guess ${WRKSRC}

pre-install:
	${MKDIR} `php-config --extension-dir`

post-install:
	dir=`php-config --extension-dir | ${SED} 's,^${LOCALBASE}/,,'`; \
	${ECHO_CMD} "$$dir/sql_relay.so" >> ${TMPPLIST}; \
	${ECHO_CMD} "@unexec rmdir %D/$$dir 2>/dev/null || true" >> ${TMPPLIST}
	@${MKDIR} ${PREFIX}/etc/php
	@${ECHO_CMD} extension=sql_relay.so \
		>> ${PREFIX}/etc/php/extensions.ini
	@${ECHO_CMD} "@exec echo extension=sql_relay.so >> %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec cp %D/etc/php/extensions.ini %D/etc/php/extensions.ini.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec grep -v extension=sql_relay\\\.so %D/etc/php/extensions.ini.orig > %D/etc/php/extensions.ini || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm %D/etc/php/extensions.ini.orig" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec [ -s %D/etc/php/extensions.ini ] || rm %D/etc/php/extensions.ini" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/etc/php 2> /dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.post.mk>
