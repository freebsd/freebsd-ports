# New ports collection makefile for:	ruby-sexp
# Date created:		24 Marth 2008
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sexp
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A ruby library to work with s-expressions

RUN_DEPENDS=	${SADIR}/multi.rb:${PORTSDIR}/devel/ruby-multi

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SADIR=		${RUBY_SITELIBDIR}

EXAMPLES=	sexp_example.rb

do-install:
	${INSTALL_DATA} ${WRKSRC}/sexp.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
