# New ports collection makefile for:	ruby-reference
# Date created:			8 February 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby-reference
PORTVERSION=	1.0
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.pragmaticprogrammer.com/ruby/downloads/files/
DISTNAME=	rubyref_html_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

WRKSRC=		${WRKDIR}/ref
NO_BUILD=	yes

DOCDIR=		${RUBY_DOCDIR}/${PORTNAME}

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${DOCDIR}

.include <bsd.port.mk>
