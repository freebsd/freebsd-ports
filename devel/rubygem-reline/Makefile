PORTNAME=	reline
PORTVERSION=	0.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Alternative GNU Readline or Editline implementation by pure Ruby
WWW=		https://github.com/ruby/reline

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-io-console>=0.5<1:devel/rubygem-io-console

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
