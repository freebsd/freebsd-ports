# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	uconv
PORTVERSION=	0.5.3
CATEGORIES=	japanese converters ruby
MASTER_SITES=	http://www.yoshidam.net/
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Unicode conversion library with Japanese codesets support for Ruby

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>
