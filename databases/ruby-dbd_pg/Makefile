# New ports collection makefile for:	dbd_pg for DBD-for-Ruby
# Date created:		9 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_pg
PORTVERSION=	0.3.9
CATEGORIES=	databases ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-dbi
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	dbd-pg-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PostgreSQL driver for DBI-for-Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${PORTSDIR}/databases/ruby-dbi \
		${RUBY_SITEARCHLIBDIR}/pg.so:${PORTSDIR}/databases/ruby-pg

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

.include <bsd.port.mk>
