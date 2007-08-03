# New ports collection makefile for:	ruby-postgres
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	ruby-postgres
PORTVERSION=	0.7.1.2006.04.06
CATEGORIES=	databases rubygems
MASTER_SITES=   ${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=     ${PORTNAME}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ruby interface to PostgreSQL library

USE_PGSQL=	yes

PG_CONFIG=	${LOCALBASE}/bin/pg_config
CONFIGURE_ARGS=	--with-pgsql-include-dir=`${PG_CONFIG} --includedir` \
		--with-pgsql-lib-dir=`${PG_CONFIG} --libdir`

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
