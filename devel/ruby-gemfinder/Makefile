# New ports collection makefile for:	Gem Finder
# Date created:		12 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gemfinder
PORTVERSION=	1.9.6
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://onestepback.org/packages/gemfinder/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A simple class browser (built with Ruby/Tk) for Ruby modules/programs

RUN_DEPENDS=	${RUBY_LIBDIR}/tk.rb:${PORTSDIR}/x11-toolkits/ruby-tk

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	doc/gemfinder.rd
RUBY_SHEBANG_FILES=	${WRKSRC}/gemfinder

DOCS=		README \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}

do-install:
	(cd ${WRKSRC}; ./install.rb --prefix=${PREFIX} --sitedir=${RUBY_SITELIBDIR})

.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
