# New ports collection makefile for:	sqlite-ruby
# Date created:		26 June 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	2.2.3
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}-ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 2

LIB_DEPENDS=	sqlite.2:${PORTSDIR}/databases/sqlite2

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_WRKSRC=	${WRKSRC}/ext
BUILD_WRKSRC=		${WRKSRC}/ext
INSTALL_WRKSRC=		${WRKSRC}/ext
INSTALL_TARGET=	site-install

DOCS=	ChangeLog LICENSE api/* doc/*

post-extract:
	${LN} -s ../lib ${WRKSRC}/ext/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
