# New ports collection makefile for:	Ruby EB
# Date created:		6 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	eb
PORTVERSION=	1.7
CATEGORIES=	japanese ruby
MASTER_SITES=	http://www.threeweb.ad.jp/~nyasu/software/
DISTNAME=	ruby-${PORTNAME}${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	eb.6:${PORTSDIR}/japanese/eb

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/ja/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/eb.html ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>
