# New ports collection makefile for:	Ruby/ODBC
# Date created:		17 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	odbc
PORTVERSION=	0.992
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.ch-werner.de/rubyodbc/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby extension library to use ODBC data sources

LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog README doc/odbc.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/test* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
