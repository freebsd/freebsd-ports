# New ports collection makefile for:	sysbench
# Date created:		2005-12-11
# Whom:			Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	sysbench
PORTVERSION=	0.4.6
CATEGORIES=	benchmarks databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	A modular, cross-platform and multi-threaded benchmark tool

USE_AUTOTOOLS=	libtool:15

OPTIONS=	MYSQL "Enable MySQL support" on \
		POSTGRESQL "Enable PostgreSQL support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--with-mysql=no
.else
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
WANT_PGSQL_VER?=	80
CONFIGURE_ARGS+=	--with-pgsql
.else
CONFIGURE_ARGS+=	--with-pgsql=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysbench/sysbench ${PREFIX}/bin
.for FILE in sb_run.sh sb_test_ps.sh
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${FILE} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
