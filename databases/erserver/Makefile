# New ports collection makefile for:	PostgreSQL eRServer
# Date created:		1 Sep 2003
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	erserver
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/erserver/stable/
DISTNAME=	${PORTNAME}_v${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Trigger-based asynchronous replication system for PostgreSQL

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		${PGINC}/executor/spi.h:${PORTSDIR}/databases/postgresql7
RUN_DEPENDS=	${JAVAJARDIR}/log4j.jar:${PORTSDIR}/java/jakarta-log4j \
		psql:${PORTSDIR}/databases/postgresql7

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	1.2+
USE_PERL5=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME} JAVA=${JAVA}
CONFIGURE_ARGS=	--with-pgincludes=${PGINC}
MAKE_ENV=	JAVA_HOME=${JAVA_HOME} JAVA=${JAVA} \
		PATH=${JAVA_HOME}/bin:${PATH}
MAKE_ARGS=	sqldir=${DATADIR} templdir=${DATADIR} docdir=${DOCSDIR} \
		libdir=${PREFIX}/lib/postgresql javadir=${JAVAJARDIR} \
		siteperldir=${SITE_PERL}

PGINC=		${PREFIX}/include/postgresql/server

pre-install:
	${MKDIR} ${DOCSDIR}

.include <bsd.port.mk>
