# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	calendar
PORTVERSION=	1.11.4r
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.funaba.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby modules to handle various calendars

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	README.en ext/sdn/README.sdncal20
DOCS_JA=	README
EXAMPLES_EN=	ext/calendar/cal*.rb

post-install:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/*.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_EN} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_JA} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${EXAMPLES_EN} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>
