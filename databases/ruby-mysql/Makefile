# New ports collection makefile for:	Ruby-MySQL
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mysql
PORTVERSION=	2.4.5
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.tmtm.org/mysql/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby module for accessing MySQL databases with a C API like interface

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.10)
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.else
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.14)
LIB_DEPENDS=	mysqlclient.14:${PORTSDIR}/databases/mysql41-client
.else
LIB_DEPENDS=	mysqlclient.12:${PORTSDIR}/databases/mysql40-client
.endif
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-mysql-dir="${LOCALBASE}"
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
