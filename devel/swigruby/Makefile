# New ports collection makefile for:	SWIGRuby
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	swigruby
PORTVERSION=	0.4.4
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.goto.info.waseda.ac.jp/~fukusima/ruby/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	swig1.1:${PORTSDIR}/devel/swig11
RUN_DEPENDS=	swig1.1:${PORTSDIR}/devel/swig11

USE_RUBY=	yes

USE_GMAKE=	yes

DOCS_EN=	ChangeLog README
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} configure.rb --with-swig=swig1.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
