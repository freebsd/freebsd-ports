# New ports collection makefile for:	DBI-for-Ruby
# Date created:		3 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbi
PORTVERSION=	0.0.4
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.sprytech.com/~rainer.perl/ruby/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_WRKSUBDIR=	yes

NO_BUILD=	yes

DOCS_EN=	README.1st lib/${PORTNAME}/doc/*

post-extract:
	${MV} ${WRKSRC}/README ${WRKSRC}/README.1st

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}/*.rb ${RUBY_SITELIBDIR}/
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/${PORTNAME}
	${MKDIR} ${RUBY_SITELIBDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
