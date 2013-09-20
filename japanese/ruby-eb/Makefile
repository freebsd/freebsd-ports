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

LIB_DEPENDS=	eb:${PORTSDIR}/japanese/eb

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

EXAMPLES=	hook2.rb test.rb

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja/
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/ja/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/eb.html ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>
