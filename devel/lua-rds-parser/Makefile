# Created by: osa
# $FreeBSD$

PORTNAME=	rds-parser
PORTVERSION=	0.0.4
CATEGORIES=	devel
MASTER_SITES=	https://github.com/agentzh/lua-rds-parser/tarball/master/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	lua-${PORTNAME}-${PORTVERSION}-${GITVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Resty-DBD-Stream (RDS) parser for Lua written in C

BROKEN=		Unfetchable due to checksum mismatch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-04-10
USE_LUA?=	5.1
GITVERSION=	0-gb46bbd8
WRKSRC=		${WRKDIR}/agentzh-lua-rds-parser-${GITVERSION:S/^0-g//}

PLIST_FILES=	%%LUA_MODLIBDIR%%/rds/parser.so
PLIST_DIRS=	%%LUA_MODLIBDIR%%/rds

NO_STAGE=	yes
do-install:
	${MKDIR} ${LUA_MODLIBDIR}/rds
	${INSTALL_PROGRAM} ${WRKSRC}/parser.so ${LUA_MODLIBDIR}/rds

.include <bsd.port.mk>
