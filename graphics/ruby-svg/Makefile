# New ports collection makefile for:	Ruby/SVG
# Date created:		8 July 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	svg
PORTVERSION=	1.0.1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://downloads.sourceforge.jp/ruby-svg/1018/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/zlib.so:${PORTSDIR}/archivers/ruby-zlib

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	README.en.rd
DOCS_JA=	README.ja.rd

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/svg
	${INSTALL_DATA} ${WRKSRC}/lib/svg/*.rb ${RUBY_SITELIBDIR}/svg/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
