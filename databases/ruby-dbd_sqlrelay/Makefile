# New ports collection makefile for:	dbd_sqlrelay for DBD-for-Ruby
# Date created:		15 November 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_sqlrelay
PORTVERSION=	${RUBY_DBI_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_DBI_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	SQLRelay driver for DBI-for-Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR} \
		${RUBY_SITEARCHLIBDIR}/sqlrelay.so:${.CURDIR}/../ruby-sqlrelay

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=lib/${PORTNAME}

DOCS_EN=	lib/${PORTNAME}/doc/*

.include "${.CURDIR}/../ruby-dbi/Makefile.common"

.include <bsd.port.mk>
