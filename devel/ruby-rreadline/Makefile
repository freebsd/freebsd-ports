# New ports collection makefile for:	Ruby Readline
# Date created:		29 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rreadline
PORTVERSION=	0.5.4
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.mag.keio.ac.jp/~hiroya/ruby/rreadline/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

NO_BUILD=	yes

post-extract:
	${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/rbsh
	${ECHO_CMD} 'ruby RubyShell.rb' >> ${WRKSRC}/rbsh

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/rbsh
	${INSTALL_SCRIPT} ${WRKSRC}/rbsh ${RUBY_EXAMPLESDIR}/${PORTNAME}/rbsh/
	${INSTALL_DATA}  ${WRKSRC}/samples/rbsh/*.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/rbsh/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
	${INSTALL_DATA}  ${WRKSRC}/README ${RUBY_DOCDIR}/${PORTNAME}/
	${INSTALL_DATA}  ${WRKSRC}/README.ja ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endif

.include <bsd.port.mk>
