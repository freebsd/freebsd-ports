# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	cdb
PORTVERSION=	0.5a
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.fan.gr.jp/~kaz/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to D. J. Bernstein's cdb (constant database) library

FETCH_DEPENDS=	${NONEXISTENT}:${CDB_PORTDIR}:build

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CDB_PORTDIR=	${PORTSDIR}/databases/cdb

INSTALL_TARGET=	site-install

OPTIONS_DEFINE=	DOCS

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -E \
		-e 's|RSTRING\(([^)]+)\)->len|RSTRING_LEN(\1)|g' \
		-e 's|RSTRING\(([^)]+)\)->ptr|RSTRING_PTR(\1)|g' \
		${WRKSRC}/cdb.c

post-extract:
	${RM} ${WRKSRC}/cdb
	${LN} -s `cd ${CDB_PORTDIR}; ${MAKE} -V WRKSRC` ${WRKSRC}/cdb

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	@(cd ${WRKSRC}/sample/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/)
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.post.mk>
