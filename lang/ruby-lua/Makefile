# New ports collection makefile for:	Ruby/Lua
# Date created:		30 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	0.0.1
CATEGORIES=	lang ruby
MASTER_SITES=	http://ruby-lua.unolotiene.com/img/18/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/liblua.a:${PORTSDIR}/lang/lua

USE_ZIP=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	site-install

post-extract:
	${ECHO} 'require "mkmf"' > ${WRKSRC}/extconf.rb
	${ECHO} 'have_library("lua") &&' >> ${WRKSRC}/extconf.rb
	${ECHO} ' have_library("lualib") &&' >> ${WRKSRC}/extconf.rb
	${ECHO} ' create_makefile("lua")' >> ${WRKSRC}/extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/rubylua.txt ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
