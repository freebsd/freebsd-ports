# New ports collection makefile for:		Programming Ruby--The Book
# Date created:			8 March 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	programmingruby
PORTVERSION=	0.2
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.rubycentral.com/downloads/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ProgrammingRuby-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

NO_BUILD=	yes

DOCDIR=		${RUBY_DOCDIR}/${PORTNAME}

do-install:
	${MKDIR} ${DOCDIR}
	${CP} -R ${WRKSRC}/* ${DOCDIR}/

.include <bsd.port.mk>
