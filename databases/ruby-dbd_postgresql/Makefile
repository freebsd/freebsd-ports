# New ports collection makefile for:	dbd_postgresql for DBD-for-Ruby
# Date created:		3 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_postgresql
PORTVERSION=	0.0.4
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://ftp.one.net/pub/users/jweirich/tools/ruby-dbi/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-dbi-postgresql-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${.CURDIR}/../ruby-dbi \
		${RUBY_SITEARCHLIBDIR}/postgres.so:${.CURDIR}/../ruby-postgres

USE_RUBY=	yes

NO_BUILD=	yes

EXAMPLES_EN=	*.rb
DOCS_EN=	README

do-install:
	${INSTALL_DATA} ${WRKSRC}/dbi/*.rb ${RUBY_SITELIBDIR}/dbi/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/dbi/${PORTNAME}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/dbi/${PORTNAME}/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/dbi/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/dbi/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
