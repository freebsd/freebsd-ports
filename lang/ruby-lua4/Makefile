# New ports collection makefile for:	Ruby/Lua
# Date created:		30 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	20010921
PORTREVISION=	1
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby extension to make Lua script language as a class

USE_LUA=	4.0
USE_ZIP=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF=	luaconf.rb
RUBY_MODNAME=	${PORTNAME}-${LUA_VER}

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	site-install

EXAMPLES=	html_ssi_lua.rb test_*

post-patch:
	@${REINPLACE_CMD} -Ee 's/[[:<:]](lua(lib)?)[[:>:]]/\1-${LUA_VER}/' \
		${WRKSRC}/${RUBY_EXTCONF}

post-configure:
	@${REINPLACE_CMD} -Ee 's|^(CPPFLAGS =.*)|\1 -I${LUA_INCDIR}|' \
		${WRKSRC}/${MAKEFILE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/rubylua.txt ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
