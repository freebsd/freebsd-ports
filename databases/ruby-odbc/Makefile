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

BROKEN_RUBY24=	yes
BROKEN_RUBY25=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/ext
BUILD_WRKSRC=		${WRKSRC}/ext
INSTALL_WRKSRC=		${WRKSRC}/ext

INSTALL_TARGET=	site-install

MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/odbc.so \
		%%RUBY_SITELIBDIR%%/cqgen.rb

EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
PORTEXAMPLES=	test

DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	COPYING ChangeLog README doc

post-extract:
	cd ${WRKSRC} && ${MV} lib ext/

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${EXAMPLESDIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
