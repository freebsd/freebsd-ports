# New ports collection makefile for:	dbd_sybase for DBD-for-Ruby
# Date created:		3 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_sybase
PORTVERSION=	${RUBY_DBI_PORTVERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	tds.0:${.CURDIR}/../freetds
RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${RUBY_DBI_PORTDIR}

BROKEN=		"This module is currently outdated and will not work with DBI versions > 0.0.4"

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=ext/${PORTNAME}

DOCS_EN=	ext/${PORTNAME}/doc/*

.include "${.CURDIR}/../ruby-dbi/Makefile.common"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${RUBY_DBI_PORTNAME}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${RUBY_DBI_PORTNAME}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
