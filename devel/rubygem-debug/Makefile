PORTNAME=	debug
PORTVERSION=	1.11.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Debugging functionality for Ruby
WWW=		https://github.com/ruby/debug

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-irb>=1.10<2:devel/rubygem-irb \
		rubygem-reline>=0.3.8:devel/rubygem-reline

USES=		gem

PLIST_FILES=	bin/rdbg

.include <bsd.port.mk>
