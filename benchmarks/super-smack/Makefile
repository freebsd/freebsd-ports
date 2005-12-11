# New ports collection makefile for:	super-smack
# Date created:		2005-12-10
# Whom:			Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	super-smack
PORTVERSION=	1.3
CATEGORIES=	benchmarks databases
MASTER_SITES=	http://vegan.net/tony/supersmack/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	A benchmarking, stress testing, and load generation tool for Databases

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-smacks-dir=${DATADIR}

OPTIONS=	MYSQL "Enable MySQL support" on \
		POSTGRESQL "Enable PostgreSQL support" off

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql
.endif

.include <bsd.port.mk>
