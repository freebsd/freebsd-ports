# $FreeBSD$

PORTNAME=	gitlab-pygments.rb
PORTVERSION=	0.5.4
PORTREVISION=	3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Exposes the pygments syntax highlighter to Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-posix-spawn>=0.3.6:devel/rubygem-posix-spawn \
		rubygem-yajl-ruby>=1.1.0:devel/rubygem-yajl-ruby

USES=		gem python:env shebangfix

NO_ARCH=	yes
USE_RUBY=	yes
SHEBANG_FILES=	lib/pygments/mentos.py vendor/pygments-main/docs/generate.py \
		vendor/pygments-main/external/lasso-builtins-generator-9.lasso \
		vendor/pygments-main/pygmentize \
		vendor/pygments-main/scripts/check_sources.py \
		vendor/pygments-main/scripts/find_codetags.py \
		vendor/pygments-main/scripts/find_error.py \
		vendor/pygments-main/scripts/reindent.py \
		vendor/pygments-main/setup.py \
		vendor/simplejson/scripts/make_docs.py

.include <bsd.port.mk>
