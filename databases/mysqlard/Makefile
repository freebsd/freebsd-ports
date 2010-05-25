# New ports collection makefile for:	mysqlard
# Date created:				31 July 2006
# Whom:					Greg Albrecht <gregoryba@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mysqlard
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	databases www
MASTER_SITES=	http://gert.sos.be/downloads/mysqlar/

MAINTAINER=	gregoryba@gmail.com
COMMENT=	A tool to collect and graph database statistics from mysql

BUILD_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_APACHE=	1.3+
USE_MYSQL=	yes

MYSQLARD_DIR?=	${PREFIX}/www/mysqlard

USE_RC_SUBR=	mysqlard.sh

MAN1=		mysqlar_graph.1
MAN8=		mysqlard.8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rrd="${LOCALBASE}" --datadir="${PREFIX}/www" \
		--sysconfdir="${PREFIX}/etc"

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
