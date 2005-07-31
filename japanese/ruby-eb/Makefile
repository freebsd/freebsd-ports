# New ports collection makefile for:	Ruby EB
# Date created:		6 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	eb
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	japanese ruby
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	ruby${PORTNAME}
MASTER_SITES=	http://ruby${PORTNAME}.sourceforge.net/
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby bind of EB library

LIB_DEPENDS=	eb.10:${PORTSDIR}/japanese/eb

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

EXAMPLES=	hook2.rb test.rb

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
