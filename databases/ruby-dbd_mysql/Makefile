# New ports collection makefile for:	dbd_mysql for DBD-for-Ruby
# Date created:		3 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_mysql
PORTVERSION=	0.0.4
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.sprytech.com/~rainer.perl/ruby/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-dbi-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${.CURDIR}/../ruby-dbi \
		${RUBY_SITEARCHLIBDIR}/mysql.so:${.CURDIR}/../ruby-mysql

USE_RUBY=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/lib/${PORTNAME}

EXAMPLES_EN=	../../examples/test1.rb
DOCS_EN=	doc/*

do-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/*.rb ${RUBY_SITELIBDIR}/dbi/
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
