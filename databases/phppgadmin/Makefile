# New ports collection makefile for: phpPgAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phppgadmin
PORTVERSION=	2.4.2
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpPgAdmin_${PORTVERSION:S/./-/g}

MAINTAINER=	nbm@FreeBSD.org

.if !defined(WITH_PHP3)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.endif
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

WRKSRC=		${WRKDIR}/phpPgAdmin
NO_BUILD=	YES

do-install:
	${MKDIR} ${PREFIX}/www/data.default/phpPgAdmin/
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/data.default/phpPgAdmin/

.include <bsd.port.mk>
