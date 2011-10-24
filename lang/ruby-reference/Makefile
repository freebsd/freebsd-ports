# New ports collection makefile for:	ruby-reference
# Date created:			8 February 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	reference
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	lang ruby
MASTER_SITES=	http://cvsup.theplanet.com/distfiles/ruby/ \
		ftp://ftp.iDaemons.org/pub/distfiles/ruby/ \
		http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rubyref_html_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
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
