# New ports collection makefile for:    pgagent
# Date created:                         June 8, 2012
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgagent
PORTVERSION=	3.2.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	pgadmin3/release/pgagent
DISTNAME=	pgAgent-${PORTVERSION}-Source

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Job scheduler for PostgreSQL

MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DSTATIC_BUILD:BOOL=NO -DWX_CONFIG_PATH:FILEPATH="${WX_CONFIG}"
USE_WX=		2.8
WX_UNICODE=	yes
USE_PGSQL=	yes
IGNORE_WITH_PGSQL=	82 83

.include <bsd.port.mk>
