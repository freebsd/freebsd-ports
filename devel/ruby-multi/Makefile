# New ports collection makefile for:	ruby-multi
# Date created:		24 Marth 2008
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	multi
PORTVERSION=	0.1
CATEGORIES=	devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A library for multiple dispatch and pattern matching in Ruby

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

EXAMPLES=	multi_example.rb

do-install:
	${INSTALL_DATA} ${WRKSRC}/multi.rb ${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/smulti.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
