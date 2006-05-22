# New ports collection makefile for:	dbd_proxy for DBD-for-Ruby
# Date created:		9 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_proxy
PORTVERSION=	${RUBY_DBI_PORTVERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_DBI_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Proxy/Server driver for DBI-for-Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR}

USE_RUBY=	yes
USE_RUBY_FEATURES=	drb
USE_RUBY_SETUP=	yes

SLAVE_PORT=	yes
MASTER_PORT=	databases/ruby-dbi

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=bin/proxyserver,${PORTNAME}

.include "${.CURDIR}/../ruby-dbi/Makefile.common"

.include <bsd.port.mk>
