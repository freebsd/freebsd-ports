# New ports collection makefile for:   ruby-tokyocabinet
# Date created:        9 September 2009
# Whom:                Damian Gerow <dgerow@afflictions.org>
#
# $FreeBSD$
#

PORTNAME=	tokyocabinet
PORTVERSION=	1.29
PORTREVISION=	3
CATEGORIES=	databases ruby
MASTER_SITES=	http://1978th.net/tokyocabinet/rubypkg/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	dgerow@FreeBSD.org
COMMENT=	Ruby interface to the Tokyo Cabinet DB engine

LIB_DEPENDS=	tokyocabinet.9:${PORTSDIR}/databases/tokyocabinet

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

#CONFIGURE_WRKSRC=	${WRKSRC}/ext
#BUILD_WRKSRC=	${WRKSRC}/ext
#INSTALL_WRKSRC=	${WRKSRC}/ext
INSTALL_TARGET=	site-install

DOCS=	doc/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
