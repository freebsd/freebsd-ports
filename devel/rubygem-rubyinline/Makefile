# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rubyinline
PORTVERSION=	3.12.4
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	RubyInline-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Inline::C allows you to embed C/Ruby directly in ruby scripts

LICENSE=	MIT

RUN_DEPENDS=	rubygem-zentest>=4.3:devel/rubygem-zentest

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

SHEBANG_FILES=	example2.rb \
		tutorial/example1.rb \
		tutorial/example2.rb
SHEBANG_LANG=	ruby2
ruby2_OLD_CMD=	/usr/local/bin/ruby17
ruby2_CMD=	${ruby_CMD}

.include <bsd.port.mk>
