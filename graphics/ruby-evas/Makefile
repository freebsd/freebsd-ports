# New ports collection makefile for:	Ruby/Evas
# Date created:		8 July 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	1.0
CATEGORIES=	graphics ruby
MASTER_SITES=	http://neugierig.org/software/ruby/evas/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	evas.6:${PORTSDIR}/graphics/evas

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDTOOL=	yes

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${BUILD_WRKSRC}
INSTALL_TARGET=	site-install

DOCS=		README doc/evas.rd doc/evas.html

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc; ${MAKE}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/tests/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
