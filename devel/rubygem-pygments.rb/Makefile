# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygments.rb
PORTVERSION=	1.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Exposes the pygments syntax highlighter to Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=1.0.0:devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

SHEBANG_FILES=	vendor/pygments-main/external/autopygmentize

post-patch:
	@${REINPLACE_CMD} -e '1d' \
		${WRKSRC}/lib/pygments/mentos.py \
		${WRKSRC}/vendor/pygments-main/external/lasso-builtins-generator-9.lasso \
		${WRKSRC}/vendor/pygments-main/pygmentize \
		${WRKSRC}/vendor/pygments-main/pygments/util.py \
		${WRKSRC}/vendor/pygments-main/scripts/check_sources.py \
		${WRKSRC}/vendor/pygments-main/scripts/debug_lexer.py \
		${WRKSRC}/vendor/pygments-main/scripts/vim2pygments.py \
		${WRKSRC}/vendor/pygments-main/setup.py \
		${WRKSRC}/vendor/simplejson/scripts/make_docs.py \
		${WRKSRC}/vendor/simplejson/setup.py

.include <bsd.port.mk>
