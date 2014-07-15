# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	o_dbm
PORTVERSION=	0.5.1
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OODB-like DBM module for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/o_dbm.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test-o_dbm.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.jp ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
