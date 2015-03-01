# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lha
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	archivers ruby
MASTER_SITES=	http://arton.no-ip.info/data/lhalib/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	lhalib-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby extension to unpack LHA-compressed files

USES=		zip
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF=	ext/extconf.rb

CONFIGURE_ARGS=	--rubyprog=${RUBY}

EXAMPLES=	test/test.rb
RUBY_SHEBANG_FILES=	${EXAMPLES}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_SCRIPT} ${EXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.0
BROKEN=		Does not build with Ruby 2.0 or Ruby 2.1
.endif
DEPRECATED=	Does not work with Ruby 2.x
EXPIRATION_DATE=	2015-03-28

.include <bsd.port.post.mk>
