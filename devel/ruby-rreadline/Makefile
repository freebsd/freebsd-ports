# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rreadline
PORTVERSION=	0.5.4
CATEGORIES=	devel ruby
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Pure Ruby implementation of the Readline library

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

NO_BUILD=	yes

DEPRECATED=	Upstream no longer exists
EXPIRATION_DATE=	2017-01-28

post-extract:
	${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/rbsh
	${ECHO_CMD} 'ruby RubyShell.rb' >> ${WRKSRC}/rbsh

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/*.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/rbsh
	${INSTALL_SCRIPT} ${WRKSRC}/rbsh ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/rbsh/
	${INSTALL_DATA}  ${WRKSRC}/samples/rbsh/*.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/rbsh/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA}  ${WRKSRC}/README ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA}  ${WRKSRC}/README.ja ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
