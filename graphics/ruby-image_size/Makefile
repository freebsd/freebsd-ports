# New ports collection makefile for:	image_size
# Date created:		13 May 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	image_size
PORTVERSION=	0.0.20020105
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.rubycgi.org/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.${PORTVERSION:E}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_RDTOOL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		readme.en.html
DOCS_JA=	readme.ja.rd readme.ja.html

do-build:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}; \
	${RUBY_RD2} image_size.rb > readme.en.html
	@cd ${WRKSRC}; \
	${RUBY_RD2} readme.ja.rd > readme.ja.html
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/image_size.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
