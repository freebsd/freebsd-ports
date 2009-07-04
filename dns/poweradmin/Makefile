# New ports collection makefile for:   poweradmin
# Date created:        19 January 2005
# Whom:                geo
#
# $FreeBSD$
#

PORTNAME=	poweradmin
PORTVERSION=	2.1.3
CATEGORIES=	dns www
MASTER_SITES=	https://www.poweradmin.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eg@fbsd.lt
COMMENT=	A set of PHP-scripts to manage PowerDNS over the web

USE_PHP=	gettext
WANT_PHP_WEB=	yes
NO_BUILD=	yes
PEARDIR=	${PREFIX}/share/pear

OPTIONS=	POSTGRESQL "Use PostgreSQL database instead of MySQL" off

SUB_FILES=	pkg-message

CFGDIR=		inc
CFGFILE=	config.inc.php

PLIST=		${WRKDIR}/plist

.include <bsd.port.pre.mk>

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${PEARDIR}/MDB2/Driver/pgsql.php:${PORTSDIR}/databases/pear-MDB2_Driver_pgsql
.else
RUN_DEPENDS+=	${PEARDIR}/MDB2/Driver/mysql.php:${PORTSDIR}/databases/pear-MDB2_Driver_mysql
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
	${CHMOD} 0640 config-me.inc.php ; \
	if ${TEST} ! -f ${CFGFILE} ; then \
		${CP} -p config-me.inc.php ${CFGFILE} ; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
