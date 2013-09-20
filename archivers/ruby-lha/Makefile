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

NO_STAGE=	yes
USE_ZIP=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF=	ext/extconf.rb

CONFIGURE_ARGS=	--rubyprog=${RUBY}

EXAMPLES=	test/test.rb
RUBY_SHEBANG_FILES=	${EXAMPLES}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_SCRIPT} ${EXAMPLES:S,^,${WRKSRC}/,} ${RUBY_MODEXAMPLESDIR}
.endif

.include <bsd.port.mk>
