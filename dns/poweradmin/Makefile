# New ports collection makefile for:   poweradmin
# Date created:        19 January 2005
# Whom:                geo
#
# $FreeBSD$
#

PORTNAME=	poweradmin
PORTVERSION=	2.1.6
CATEGORIES=	dns www
MASTER_SITES=	SF/${PORTNAME} \
		https://www.poweradmin.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eg@fbsd.lt
COMMENT=	A set of PHP-scripts to manage PowerDNS over the web

USE_PHP=	gettext session mcrypt
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PEARDIR=	${PREFIX}/share/pear

OPTIONS=	MYSQL	"Use Mysql database support" on \
		PGSQL	"Use Pgsql database support" off

SUB_FILES=	pkg-message

CFGDIR=		inc
CFGFILE=	config.inc.php

PLIST=		${WRKDIR}/plist

.include <bsd.port.options.mk>

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PEARDIR}/MDB2/Driver/mysql.php:${PORTSDIR}/databases/pear-MDB2_Driver_mysql
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${PEARDIR}/MDB2/Driver/pgsql.php:${PORTSDIR}/databases/pear-MDB2_Driver_pgsql
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -rf "install"

post-patch:
	cd ${WRKSRC} ; \
	${FIND} . ! -type d ! -name config-me.inc.php | ${SORT} | \
		${SED} -e "s,^\.,%%WWWDIR%%,"             >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk             >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
		-e 's!^\./${CFGDIR}$$!@dirrmtry %%WWWDIR%%/${CFGDIR}!' \
		-e 's!^\.$$!@dirrmtry %%WWWDIR%%!' \
		-e 's!^\.!@dirrm %%WWWDIR%%!'		>>${PLIST}

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ) ; do \
		dst=${WWWDIR}$${src#.} ; \
		if ${TEST} -d $$src ; then \
			${MKDIR} $$dst ; \
		else \
			${INSTALL_DATA} $$src $$dst ; \
		fi \
	done

install-conf: install-app
	cd ${WWWDIR}/${CFGDIR} ; \
	${CHMOD} 0644 config-me.inc.php ; \
	if ${TEST} ! -f ${CFGFILE} ; then \
		${CP} -p config-me.inc.php ${CFGFILE} ; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
