# New ports collection makefile for:	rice
# Date created:		30 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rice
PORTVERSION=	0.0.0.1
CATEGORIES=	irc ruby
MASTER_SITES=	http://arika.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	${CP} -R ${WRKSRC}/rice ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
