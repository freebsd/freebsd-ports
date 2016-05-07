# Created by: TOMIDA, Hiroaki <t.hiroaki.209 at gmail.com>
# $FreeBSD$

PORTNAME=	taglib
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.hakubi.us/wp-content/uploads/software/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-taglib-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	t.hiroaki.209@gmail.com
COMMENT=	Ruby library wrapping the Taglib library

LICENSE=	MIT

LIB_DEPENDS=	libtag.so:audio/taglib

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USES=		tar:bzip2

RUBY_RD_FILES=	taglib.rb

DOCS=		README

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/taglib.rb ${STAGEDIR}${RUBY_SITELIBDIR}
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}

.include <bsd.port.mk>
