# New ports collection makefile for:	sqlite3-ruby
# Date created:		26 June 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	1.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	sqlite-ruby
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

GEM_NAME=	${DISTNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
