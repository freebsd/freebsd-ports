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

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension to make Lua script language as a class

LIB_DEPENDS=	lua.5:${PORTSDIR}/lang/lua

CONFLICTS=	${RUBY_PKGNAMEPREFIX}lua4-[0-9]*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
CONFIGURE_ARGS=	-- --with-lua-dir=${LOCALBASE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
