# New ports collection makefile for:	Ruby-property
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	property
PORTVERSION=	19990308
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.ueda.info.waseda.ac.jp/~igarashi/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${PERL} -i -pe 's|rubyapi.css|../rubyapi.css|g' ${WRKSRC}/Properties-ja.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/property.rb ${RUBY_SITELIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/property/ja
.for f in property-example.rb test.default property.README Properties.html rubyapi.css
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/property
.endfor
.for f in property.README.ja Properties-ja.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/property/ja
.endfor
.endif

.include <bsd.port.mk>
