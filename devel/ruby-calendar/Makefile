# New ports collection makefile for:	Ruby-calendar
# Date created:		4 November 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	calendar
PORTVERSION=	1.10.2r
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.funaba.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

MAKE_ARGS=	RUBY="${RUBY}"
INSTALL_TARGET=	site-install

DOCS_EN=	README.en sdn/README.sdncal20
DOCS_JA=	README
EXAMPLES_EN=	calendar/cal.rb

post-extract:
	${MKDIR} ${WRKSRC}/calendar/lib
	${MV} ${WRKSRC}/calendar/calclass.rb ${WRKSRC}/calendar/lib/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/calendar
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/calendar/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/calendar/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/calendar/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/calendar/ja/
.endfor
.endif

.include <bsd.port.mk>
