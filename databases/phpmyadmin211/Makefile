# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpMyAdmin
PORTVERSION=	2.5.4
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpmyadmin
DISTFILES=	${DISTNAME}-${PHP_SUFX}${EXTRACT_SUFX}

MAINTAINER=	nbm@FreeBSD.org
COMMENT=	A set of PHP-scripts to adminstrate MySQL over the web

.if defined(WITH_PHP3)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.endif

USE_BZIP2=	yes
NO_BUILD=	yes

MYADMDIR?=	www/data/phpMyAdmin

.if defined(WITH_PHP3)
PHP_SUFX=	php3
EXTRA_PATCHES=	files/fix-libraries::display_tbl.lib.php3 files/fix-tbl_relation.php3
.else
USE_PHP=	yes
PHP_SUFX=	php
EXTRA_PATCHES=	files/fix-libraries::display_tbl.lib.php files/fix-tbl_relation.php
.endif

PLIST_SUB+=	MYADMDIR=${MYADMDIR} PHP_SUFX=${PHP_SUFX}

post-patch:
	@${MV} ${WRKSRC}/config.inc.${PHP_SUFX} ${WRKSRC}/config.inc.${PHP_SUFX}.sample
	@${RM} ${WRKSRC}/*.orig ${WRKSRC}/libraries/*.orig

do-install:
	@${MKDIR} ${PREFIX}/${MYADMDIR}
	@${FIND} ${WRKSRC} ! -path '*/CVS*' ! -path '*/.cvsignore' | \
		${XARGS} -n1 ${SH} -c 'if ${TEST} -d $$0; \
			then ${MKDIR} ${PREFIX}/${MYADMDIR}$${0#${WRKSRC}}; \
			else ${INSTALL_DATA} $$0 ${PREFIX}/${MYADMDIR}$${0#${WRKSRC}}; fi'

.include <bsd.port.mk>
