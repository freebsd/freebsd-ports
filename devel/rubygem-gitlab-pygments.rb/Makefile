# $FreeBSD$

PORTNAME=	gitlab-pygments.rb
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Exposes the pygments syntax highlighter to Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-posix-spawn>=0.3.6:devel/rubygem-posix-spawn \
		rubygem-yajl-ruby>=1.1.0:devel/rubygem-yajl-ruby

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e '1d' \
		${WRKSRC}/vendor/pygments-main/external/lasso-builtins-generator-9.lasso \
		${WRKSRC}/vendor/pygments-main/scripts/find_error.py \
		${WRKSRC}/vendor/pygments-main/scripts/reindent.py \
		${WRKSRC}/vendor/pygments-main/scripts/check_sources.py \
		${WRKSRC}/vendor/pygments-main/scripts/find_codetags.py \
		${WRKSRC}/vendor/pygments-main/setup.py \
		${WRKSRC}/vendor/pygments-main/ez_setup.py \
		${WRKSRC}/vendor/pygments-main/docs/generate.py \
		${WRKSRC}/vendor/simplejson/scripts/make_docs.py

.include <bsd.port.mk>
