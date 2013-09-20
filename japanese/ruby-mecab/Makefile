# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.996
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MeCab library module for Ruby

LICENSE=	BSD GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	mecab:${PORTSDIR}/japanese/mecab

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONSFILE=	${PORT_DBDIR}/ja-ruby-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/bindings.html ${RUBY_MODDOCDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
