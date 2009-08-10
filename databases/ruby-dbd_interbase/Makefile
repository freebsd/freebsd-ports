# New ports collection makefile for:	dbd_interbase for DBD-for-Ruby
# Date created:		16 January 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_interbase
PORTVERSION=	${RUBY_DBI_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_DBI_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	InterBase driver for DBI-for-Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR} \
		${RUBY_SITEARCHLIBDIR}/fb.so:${.CURDIR}/../ruby-interbase

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
