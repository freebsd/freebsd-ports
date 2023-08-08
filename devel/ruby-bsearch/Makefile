PORTNAME=	bsearch
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://0xcc.net/ruby-bsearch/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Binary search library for Ruby
WWW=		http://0xcc.net/ruby-bsearch/

USES=	ruby

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bsearch.rb ${STAGEDIR}${RUBY_SITELIBDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${RUBY_MODDOCDIR}

.include <bsd.port.mk>
