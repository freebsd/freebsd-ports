# $FreeBSD$

PORTNAME=	eb
PORTVERSION=	2.6
PORTREVISION=	6
CATEGORIES=	japanese ruby
MASTER_SITES=	http://rubyeb.sourceforge.net/ \
		SF/rubyeb/rubyeb/rubyeb-${PORTVERSION}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bind of EB library

LIB_DEPENDS=	libeb.so:japanese/eb

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

EXAMPLES=	hook2.rb test.rb

OPTIONS_DEFINE=	DOCS

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/ja/
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/ja/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/eb.html ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.post.mk>
