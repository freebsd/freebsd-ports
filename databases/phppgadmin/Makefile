# New ports collection makefile for: phpPgAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phppgadmin
PORTVERSION=	2.2.1.p1
CATEGORIES=	databases www
MASTER_SITES=	ftp://ftp.greatbridge.org/pub/phppgadmin/stable/
DISTNAME=	phpPgAdmin_2-2-1-pl1

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/pgsql/lib/libpq.so:${PORTSDIR}/databases/postgresql7
.if defined(WITH_PHP4)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.endif

WRKSRC=		${WRKDIR}/phpPgAdmin
NO_BUILD=	YES

do-install:
	${MKDIR} ${PREFIX}/www/data.default/phpPgAdmin/
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/data.default/phpPgAdmin/


.include <bsd.port.mk>
