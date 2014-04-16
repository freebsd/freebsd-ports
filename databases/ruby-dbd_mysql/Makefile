# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	dbd_mysql
PORTVERSION=	0.4.4
CATEGORIES=	databases ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-dbi
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	dbd-mysql-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MySQL driver for DBI-for-Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${PORTSDIR}/databases/ruby-dbi \
		${RUBY_SITEARCHLIBDIR}/mysql.so:${PORTSDIR}/databases/ruby-mysql

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

.include <bsd.port.mk>
