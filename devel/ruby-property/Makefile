# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	property
PORTVERSION=	19990308
CATEGORIES=	devel ruby
MASTER_SITES=	LOCAL/fenner/ruby-contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple properties scheme for Ruby

USE_RUBY=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DEPRECATED=	Upstream no longer exists
EXPIRATION_DATE=	2017-01-28

post-patch:
	${RUBY} -i -pe 'gsub /rubyapi\.css/, "../rubyapi.css"' ${WRKSRC}/Properties-ja.html

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/property.rb ${STAGEDIR}${RUBY_SITELIBDIR}
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in property-example.rb test.default property.README Properties.html rubyapi.css
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}
.endfor
.for f in property.README.ja Properties-ja.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.endfor

.include <bsd.port.mk>
