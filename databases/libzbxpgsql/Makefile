# Created by: Martin Waschbuesch <martin@waschbuesch.de>
# $FreeBSD$

PORTNAME=	libzbxpgsql
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://s3.cavaliercoder.com/libzbxpgsql/

MAINTAINER=	martin@waschbuesch.de
COMMENT=	Zabbix agent module for comprehensive monitoring of PostgreSQL servers

LICENSE=	GPLv2

BUILD_DEPENDS=	${NONEXISTENT}:net-mgmt/zabbix3-agent:patch
RUN_DEPENDS=	${LOCALBASE}/sbin/zabbix_agentd:net-mgmt/zabbix3-agent

USES=		autoreconf gmake libtool pgsql
GNU_CONFIGURE=	yes
GET_ZBX_WRKSRC=	cd ${.CURDIR:H:H}/net-mgmt/zabbix3-agent && make -V WRKSRC
CONFIGURE_ARGS=	--with-zabbix=$$(${GET_ZBX_WRKSRC})

USE_LDCONFIG=	yes

do-install:
		${INSTALL_LIB} ${WRKSRC}/src/.libs/libzbxpgsql.so ${STAGEDIR}${PREFIX}/lib/libzbxpgsql.so
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_MAN} ${WRKSRC}/template_postgresql_server.xml ${STAGEDIR}${EXAMPLESDIR}/template_postgresql_server.xml.sample

.include <bsd.port.mk>
