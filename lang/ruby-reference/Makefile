# New ports collection makefile for:	ruby-reference
# Date created:			8 February 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby-reference
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.pragmaticprogrammer.com/ruby/downloads/files/
DISTNAME=	rubyref_html_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby Class and Module Reference, in HTML format

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

WRKSRC=		${WRKDIR}/ref
NO_BUILD=	yes

do-install:
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${RUBY_MODDOCDIR}

.include <bsd.port.mk>
