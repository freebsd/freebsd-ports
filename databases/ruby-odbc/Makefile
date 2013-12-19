# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	odbc
PORTVERSION=	0.99991
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.ch-werner.de/rubyodbc/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby extension library to use ODBC data sources

LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/ext
BUILD_WRKSRC=		${WRKSRC}/ext
INSTALL_WRKSRC=		${WRKSRC}/ext

INSTALL_TARGET=	site-install

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/odbc.so \
		%%RUBY_SITELIBDIR%%/cqgen.rb

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
PORTEXAMPLES=	test

DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	COPYING ChangeLog README doc
.endif

post-extract:
	cd ${WRKSRC} && ${MV} lib ext/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${EXAMPLESDIR}/
.endfor
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
