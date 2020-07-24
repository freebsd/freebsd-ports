# Created by: Damian Gerow <dgerow@afflictions.org>
# $FreeBSD$

PORTNAME=	tokyocabinet
PORTVERSION=	1.31
CATEGORIES=	databases ruby
MASTER_SITES=	https://dbmx.net/${PORTNAME}/rubypkg/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	dgerow@afflictions.org
COMMENT=	Ruby interface to the Tokyo Cabinet DB engine

LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=	doc/*

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
