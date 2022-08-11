PORTNAME=	rubyinline
PORTVERSION=	3.12.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	RubyInline-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Inline::C allows you to embed C/Ruby directly in ruby scripts

LICENSE=	MIT

RUN_DEPENDS=	rubygem-zentest>=4.3:devel/rubygem-zentest

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	example2.rb \
		tutorial/example1.rb \
		tutorial/example2.rb
SHEBANG_LANG=	ruby2
ruby2_OLD_CMD=	/usr/local/bin/ruby17
ruby2_CMD=	${ruby_CMD}

.include <bsd.port.mk>
