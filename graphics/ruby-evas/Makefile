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

RUBY_RD_FILES=	# defined

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${BUILD_WRKSRC}
INSTALL_TARGET=	site-install

DOCS=		README doc/evas.*

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
.if !defined(RUBY_NO_RD_HTML)
	cd ${WRKSRC}/doc; ${MAKE}
.endif
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/tests/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif
