# New ports collection makefile for:	ruby-shout
# Date created:		10 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	shout
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.dingoskidneys.com/~jaredj/downloads/
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby binding to the libshout library

LIB_DEPENDS=	shout.4:${PORTSDIR}/audio/libshout2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		README	doc

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 500000
BROKEN=		Does not compile
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
