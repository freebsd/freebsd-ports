# New ports collection makefile for:	Ruby-cdb
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cdb
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.fan.gr.jp/~kaz/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${CDB_PORTDIR}:build

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CDB_PORTDIR=	${PORTSDIR}/databases/cdb

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
INSTALL_TARGET=	site-install

post-extract:
	${RM} -f ${WRKSRC}/cdb
	${LN} -s `cd ${CDB_PORTDIR}; ${MAKE} -V WRKSRC` ${WRKSRC}/cdb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
