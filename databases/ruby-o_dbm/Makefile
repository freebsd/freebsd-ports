# New ports collection makefile for:	o_dbm - ObjectDBM
# Date created:		16 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	o_dbm
PORTVERSION=	0.5.1
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.rubyist.net/~keiju/src/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An OODB-like DBM module for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/o_dbm.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test-o_dbm.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.jp ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
