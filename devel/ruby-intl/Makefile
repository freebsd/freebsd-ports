# New ports collection makefile for:	Ruby-intl
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	intl
PORTVERSION=	0.11
PORTREVISION=	5
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.page.sannet.ne.jp/hirata-naoto/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A simple wrapper of GNU gettext for Ruby

USE_GETTEXT=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/po/
	${INSTALL_DATA} ${WRKSRC}/hello.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/ja.po ${RUBY_MODEXAMPLESDIR}/po/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.jp ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
