PORTNAME=	readline-ext
PORTVERSION=	0.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide an interface for GNU Readline and Edit Line (libedit)
WWW=		https://github.com/ruby/readline-ext

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

USES=		gem

OPTIONS_SINGLE=	EDIT
OPTIONS_SINGLE_EDIT=	LIBEDIT READLINE
OPTIONS_DEFAULT=LIBEDIT

LIBEDIT_USES=		libedit
READLINE_USES=		readline

.include <bsd.port.mk>
