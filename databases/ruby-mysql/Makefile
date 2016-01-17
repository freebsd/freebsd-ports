# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mysql
PORTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.tmtm.org/downloads/mysql/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby module for accessing MySQL databases with a C API like interface

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

OPTIONS_DEFINE=	DOCS

USE_MYSQL=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-mysql-config
INSTALL_TARGET=	site-install
MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/mysql.so

DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/tommy.css ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README_ja.html ${STAGEDIR}${DOCSDIR}/ja/
	${LN} -fs ../tommy.css ${STAGEDIR}${DOCSDIR}/ja/

.include <bsd.port.mk>
