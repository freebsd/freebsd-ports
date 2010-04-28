# New ports collection makefile for:	Ruby/Lua5
# Date created:		30 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	lua5
PORTVERSION=	0.2.2
PORTEPOCH=	1
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.moonwolf.com/ruby/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rub-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby extension to make Lua script language as a class

USE_LUA=	5.0
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
CONFIGURE_ARGS=	-- --with-lua-include=${LUA_INCDIR} --with-lua-lib=${LUA_LIBDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|\(create_makefile("lua\)")|\1-${LUA_VER}")|' \
		${WRKSRC}/ext/lua/extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}
.endif

.include <bsd.port.mk>
