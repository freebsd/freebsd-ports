# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	image_size
PORTVERSION=	0.0.20040618
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.rubycgi.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.${PORTVERSION:E}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library to measure the size of a given image file

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

DOCS=		readme.ja.rd readme.rd

DEPRECATED=	Upstream no longer active
EXPIRATION_DATE=	2017-01-28

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/image_size.rb ${STAGEDIR}${RUBY_SITELIBDIR}/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}
.endfor

.include <bsd.port.mk>
