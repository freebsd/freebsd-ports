# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lha
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	archivers ruby
MASTER_SITES=	http://arton.no-ip.info/data/lhalib/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	lhalib-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby extension to unpack LHA-compressed files

USES=		zip shebangfix
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF=	ext/extconf.rb

CONFIGURE_ARGS=	--rubyprog=${RUBY}

EXAMPLES=	test/test.rb
SHEBANG_FILES=	${EXAMPLES}

OPTIONS_DEFINE=	DOCS

# We don't have executables in this package, but rake uses
# INSTALL_PROG for shared libraries:
MAKE_ARGS=	INSTALL_PROG="${INSTALL_LIB}"

post-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_SCRIPT} ${EXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}

test check regression-test: build
	cd ${WRKSRC}/test && ${RUBY} -I${WRKSRC} test.rb

.include <bsd.port.mk>
