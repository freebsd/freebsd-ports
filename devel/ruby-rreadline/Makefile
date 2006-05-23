# New ports collection makefile for:	Ruby Readline
# Date created:		29 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rreadline
PORTVERSION=	0.5.4
CATEGORIES=	devel ruby
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure Ruby implementation of the Readline library

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

NO_BUILD=	yes

post-extract:
	${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/rbsh
	${ECHO_CMD} 'ruby RubyShell.rb' >> ${WRKSRC}/rbsh

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/rbsh
	${INSTALL_SCRIPT} ${WRKSRC}/rbsh ${RUBY_MODEXAMPLESDIR}/rbsh/
	${INSTALL_DATA}  ${WRKSRC}/samples/rbsh/*.rb ${RUBY_MODEXAMPLESDIR}/rbsh/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA}  ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	${INSTALL_DATA}  ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
