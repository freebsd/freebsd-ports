# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpMyAdmin
PORTVERSION=	2.3.0.rc4
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpmyadmin
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.rc/-rc/}
DISTFILES=	${DISTNAME}-${PHP_VERSION}${EXTRACT_SUFX}

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqlclient.so:${PORTSDIR}/databases/mysql323-client
.if !defined(WITH_PHP3)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
PHP_VERSION=	php
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
PHP_VERSION=	php3
.endif

USE_BZIP2=	yes
NO_BUILD=	yes

MYADMDIR?=	www/data.default/phpMyAdmin

ORIG_PLIST=	${PKGDIR}/pkg-plist
PLIST=		${WRKDIR}/PLIST
PLIST_SUB+=	MYADMDIR=${MYADMDIR} PHP_VERSION=${PHP_VERSION}

post-patch:
	@${MV}	${WRKSRC}/config.inc.${PHP_VERSION} ${WRKSRC}/config.inc.${PHP_VERSION}.sample

do-install:
	@${CP}	${ORIG_PLIST} ${PLIST}
	@f=${MYADMDIR}; while ${TEST} $${#f} -gt 0; do \
		${ECHO} "@unexec rmdir %D/$$f || true"; \
		f=`${ECHO} $$f | ${SED} -e 's,/*[^/]*$$,,'`; \
	done >> ${PLIST}
	@${MKDIR} ${PREFIX}/${MYADMDIR}
	@${FIND} ${WRKSRC} ! -path '*/CVS*' | ${XARGS} -n1 ${SH} -c 'if ${TEST} -d $$0; \
			then ${MKDIR} ${PREFIX}/${MYADMDIR}$${0#${WRKSRC}}; \
			else ${INSTALL_DATA} $$0 ${PREFIX}/${MYADMDIR}$${0#${WRKSRC}}; fi'

.include <bsd.port.mk>
