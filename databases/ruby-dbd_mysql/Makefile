# New ports collection makefile for:	dbd_mysql for DBD-for-Ruby
# Date created:		3 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_mysql
PORTVERSION=	${RUBY_DBI_PORTVERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_DBI_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	MySQL driver for DBI-for-Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR} \
		${RUBY_SITEARCHLIBDIR}/mysql.so:${.CURDIR}/../ruby-mysql

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

SLAVE_PORT=	yes
MASTER_PORT=	databases/ruby-dbi

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=lib/${PORTNAME}

DOCS_EN=	lib/${PORTNAME}/doc/*

.include "${.CURDIR}/../ruby-dbi/Makefile.common"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
