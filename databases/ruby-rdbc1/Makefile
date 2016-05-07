# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rdbc1
PORTVERSION=	001103
PORTREVISION=	3
CATEGORIES=	databases ruby
MASTER_SITES=	http://homepage3.nifty.com/guion/SOFT/RDBC/ \
		ftp://ftp.dinoex.de/pub/approved/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Database Connectivity

RUN_DEPENDS=	rubygem-pg>=0:databases/rubygem-pg

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USES=		dos2unix tar:tgz

DOS2UNIX_FILES=	ora_rdbc1.rb pg_rdbc1.rb rdbc1.rb sample/test1.rb

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rb ${STAGEDIR}${RUBY_SITELIBDIR}/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	cd ${WRKSRC}/doc/en/ && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/doc/ja/ && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>
