# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.996
PORTREVISION=	1
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	https://drive.google.com/uc?export=download&id=0B4y35FiV1wh7VUNlczBWVDZJbE0&dummy=/
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MeCab library module for Ruby

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libmecab.so:japanese/mecab

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

OPTIONS_DEFINE=	DOCS EXAMPLES

DEPRECATED=Upstream no longer active
EXPIRATION_DATE=2017-01-28

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/MeCab.so
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/bindings.html ${STAGEDIR}${RUBY_MODDOCDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.post.mk>
