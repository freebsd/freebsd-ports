# New ports collection makefile for:	Ruby-MySQL
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mysql
PORTVERSION=	2.8.2
CATEGORIES=	databases ruby
MASTER_SITES=	RF/mysql-ruby \
		http://www.tmtm.org/downloads/mysql/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby module for accessing MySQL databases with a C API like interface

USE_MYSQL=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-mysql-config
INSTALL_TARGET=	site-install

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/mysql.so

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/tommy.css ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README_ja.html ${DOCSDIR}/ja/
	${LN} -fs ../tommy.css ${DOCSDIR}/ja/
.endif

.include <bsd.port.post.mk>
