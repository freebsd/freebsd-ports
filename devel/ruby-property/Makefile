# New ports collection makefile for:	Ruby-property
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	property
PORTVERSION=	19990308
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Simple properties scheme for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${RUBY} -i -pe 'gsub /rubyapi\.css/, "../rubyapi.css"' ${WRKSRC}/Properties-ja.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/property.rb ${RUBY_SITELIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in property-example.rb test.default property.README Properties.html rubyapi.css
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.for f in property.README.ja Properties-ja.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja
.endfor
.endif

.include <bsd.port.mk>
