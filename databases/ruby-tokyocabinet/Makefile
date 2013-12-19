# Created by: Damian Gerow <dgerow@afflictions.org>
# $FreeBSD$

PORTNAME=	tokyocabinet
PORTVERSION=	1.31
CATEGORIES=	databases ruby
MASTER_SITES=	http://fallabs.com/${PORTNAME}/rubypkg/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	dgerow@afflictions.org
COMMENT=	Ruby interface to the Tokyo Cabinet DB engine

LIB_DEPENDS=	libtokyocabinet.so:${PORTSDIR}/databases/tokyocabinet

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=	doc/*

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
