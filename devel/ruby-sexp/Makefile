# New ports collection makefile for:	ruby-sexp
# Date created:		24 Marth 2008
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sexp
PORTVERSION=	0.2.1
PORTREVISION=	0
CATEGORIES=	devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ruby library to work with s-expressions

RUN_DEPENDS=	rubygem-rparsec>0:${PORTSDIR}/devel/rubygem-rparsec

USE_RUBY=	yes
NO_BUILD=	yes

SADIR=		${RUBY_SITELIBDIR}

EXAMPLES=	example.rb

do-install:
	${INSTALL_DATA} ${WRKSRC}/sexp.rb ${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/sexpressions.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
