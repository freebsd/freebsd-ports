# New ports collection makefile for:	dbd_msql for DBD-for-Ruby
# Date created:		10 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_msql
PORTVERSION=	${RUBY_DBI_PORTVERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_DBI_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	mSQL driver for DBI-for-Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR} \
		${RUBY_SITEARCHLIBDIR}/msql.so:${.CURDIR}/../ruby-msql

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

SLAVE_PORT=	yes
MASTER_PORT=	databases/ruby-dbi

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=${PORTNAME}

EXPIRATION_DATE=	2009-10-01
DEPRECATED=	no longer under development

.include "${.CURDIR}/../ruby-dbi/Makefile.common"

.include <bsd.port.mk>
