# New ports collection makefile for:	mysqlard
# Date created:				31 July 2006
# Whom:					Greg Albrecht <gregoryba@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mysqlard
PORTVERSION=	1.0.0
PORTREVISION=	6
CATEGORIES=	databases www
MASTER_SITES=	http://gert.sos.be/downloads/mysqlar/

MAINTAINER=	gregoryba@gmail.com
COMMENT=	A tool to collect and graph database statistics from MySQL

BUILD_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_APACHE=	20+
USE_MYSQL=	yes

MYSQLARD_DIR?=	${PREFIX}/www/mysqlard

USE_RC_SUBR=	mysqlard

MAN1=		mysqlar_graph.1
MAN8=		mysqlard.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rrd="${LOCALBASE}" --datadir="${PREFIX}/www" \
		--sysconfdir="${PREFIX}/etc"

SUB_FILES=	pkg-message

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
