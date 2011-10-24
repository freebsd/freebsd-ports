# New ports collection makefile for:	Ruby-cdb
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cdb
PORTVERSION=	0.5a
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.fan.gr.jp/~kaz/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby interface to D. J. Bernstein's cdb (constant database) library

BUILD_DEPENDS=	${NONEXISTENT}:${CDB_PORTDIR}:build

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CDB_PORTDIR=	${PORTSDIR}/databases/cdb

INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -E \
		-e 's|RSTRING\(([^)]+)\)->len|RSTRING_LEN(\1)|g' \
		-e 's|RSTRING\(([^)]+)\)->ptr|RSTRING_PTR(\1)|g' \
		${WRKSRC}/cdb.c

post-extract:
	${RM} -f ${WRKSRC}/cdb
	${LN} -s `cd ${CDB_PORTDIR}; ${MAKE} -V WRKSRC` ${WRKSRC}/cdb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	@(cd ${WRKSRC}/sample/ && ${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR}/)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.post.mk>
