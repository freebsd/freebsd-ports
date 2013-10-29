# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	dbi
PORTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	databases ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-dbi
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DBI-for-Ruby - a common interface for SQL-based databases

RUN_DEPENDS=	${RUBY_SITELIBDIR}/aspectr.rb:${PORTSDIR}/devel/ruby-aspectr \
    		rubygem-deprecated2>=2.0.0:${PORTSDIR}/devel/rubygem-deprecated2

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
