# New ports collection makefile for:	dbd_interbase for DBD-for-Ruby
# Date created:		16 January 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_interbase
PORTVERSION=	${RUBY_DBI_PORTVERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR} \
		${RUBY_SITEARCHLIBDIR}/interbase.so:${.CURDIR}/../ruby-interbase

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=lib/${PORTNAME}

.include "${.CURDIR}/../ruby-dbi/Makefile.common"

.include <bsd.port.mk>
