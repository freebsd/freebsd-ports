# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	dump.rb
PORTVERSION=	0.2
CATEGORIES=	converters ruby
MASTER_SITES=	http://www.geocities.co.jp/SiliconValley-Oakland/2986/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:R}.txt
EXTRACT_SUFX=	# none
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Binary data dumper module for Ruby

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	%%RUBY_SITELIBDIR%%/dump.rb
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	.

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}

.include <bsd.port.mk>
