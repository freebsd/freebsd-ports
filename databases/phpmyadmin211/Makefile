# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpmyadmin
PORTVERSION=	2.1.0
CATEGORIES=	databases www
MASTER_SITES=	http://phpwizard.net/projects/phpMyAdmin/
DISTNAME=	phpMyAdmin_${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqlclient.so:${PORTSDIR}/databases/mysql323-client
.if defined(WITH_PHP4)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.endif

WRKSRC=		${WRKDIR}/phpMyAdmin
NO_BUILD=	YES

do-install:
	${MKDIR} ${PREFIX}/www/data.default/phpMyAdmin/
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/data.default/phpMyAdmin/

.include <bsd.port.mk>
