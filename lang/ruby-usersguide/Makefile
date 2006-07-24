# New ports collection makefile for:	ruby-usersguide
# Date created:			30 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	usersguide
PORTVERSION=	20051121
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.rubyist.net/~slagell/ruby/ \
		http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-uguide-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Ruby users guide, in HTML format

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

WRKSRC=		${WRKDIR}/rg
NO_BUILD=	yes
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*

do-install:
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${RUBY_MODDOCDIR}

.include <bsd.port.mk>
