# New ports collection makefile for:	dbd_sybase for DBD-for-Ruby
# Date created:		3 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dbd_sybase
PORTVERSION=	0.0.4
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.sprytech.com/~rainer.perl/ruby/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-dbi-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	tds.0:${.CURDIR}/../freetds
RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${.CURDIR}/../ruby-dbi

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ext/${PORTNAME}
INSTALL_TARGET=	site-install

DOCS_EN=	doc/*

post-install:
	cd ${RUBY_SITEARCHLIBDIR} && ${MV} ${PORTNAME}.so dbi/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/dbi/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/dbi/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
