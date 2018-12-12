# Created by: Martin Waschbuesch <martin@waschbuesch.de>
# $FreeBSD$

PORTNAME=	libzbxpgsql
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	databases
PKGNAMEPREFIX=	zabbix22-

MAINTAINER=	martin@waschbuesch.de
COMMENT=	Zabbix agent module for comprehensive monitoring of PostgreSQL servers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${NONEXISTENT}:net-mgmt/${PKGNAMEPREFIX}agent:patch
RUN_DEPENDS=	zabbix_agentd:net-mgmt/${PKGNAMEPREFIX}agent
LIB_DEPENDS=	libconfig.so:devel/libconfig

CONFLICTS=	zabbix[0-13-9][0-13-9]-libzbxpgsql zabbix[0-9]-libzbxpgsql

USES=		autoreconf gmake libtool pgsql

USE_GITHUB=	yes
GH_ACCOUNT=	cavaliercoder

GNU_CONFIGURE=	yes
GET_ZBX_WRKSRC=	cd ${.CURDIR:H:H}/net-mgmt/${PKGNAMEPREFIX}agent && make -V WRKSRC
CONFIGURE_ARGS=	--with-zabbix=$$(${GET_ZBX_WRKSRC})

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES

PORTSCOUT=	skipv:latest,gh-pages

do-install:
		${INSTALL_LIB} ${WRKSRC}/src/.libs/libzbxpgsql.so ${STAGEDIR}${PREFIX}/lib/libzbxpgsql.so

do-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/templates/*.xml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
