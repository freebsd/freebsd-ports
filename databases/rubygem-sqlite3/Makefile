# New ports collection makefile for:	sqlite3-ruby
# Date created:		26 June 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	0.5.0
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/2301/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes

NO_BUILD=	yes

DOCS=	ChangeLog LICENSE api/* doc/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
