# New ports collection makefile for:	sqlite3-ruby
# Date created:		26 June 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	1.2.5
CATEGORIES=	databases rubygems
MASTER_SITES=	RUBYFORGE/sqlite-ruby
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

CONFIGURE_ARGS+=--with-sqlite3-dir=${LOCALBASE}

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
