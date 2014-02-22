# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	libarchive
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	archivers ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby bindings for libarchive

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ext

DOCS=		README.txt doc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	cd ${WRKDIR}; ${COPYTREE_SHARE} "${DOCS}" ${STAGEDIR}${RUBY_MODDOCDIR}/


.include <bsd.port.mk>
