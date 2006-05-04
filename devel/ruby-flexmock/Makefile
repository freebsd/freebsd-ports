# New ports collection makefile for:	Ruby/FlexMock
# Date created:		18 November 2005
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	flexmock
PORTVERSION=	0.2.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/9301/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	boumenot@gmail.com
COMMENT=	A simple mock object for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=	CHANGELOG README

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
