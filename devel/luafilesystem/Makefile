# New ports collection makefile for:   luafilesystem
# Date created:                        28 Mar 2010
# Whom:                                Kelly Hays <kelly.hays@jkhfamily.org>
#
# $FreeBSD$
#

PORTNAME=	luafilesystem
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/3931/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	kelly.hays@jkhfamily.org
COMMENT=	Library to access directory structure and file attributes

LICENSE=	MIT

USE_LUA=	5.1

PLIST_FILES=	%%LUA_MODLIBDIR%%/lfs.so
PORTDOCS=	*

do-build:
	cd ${WRKSRC}/src && \
		${CC} -O2 -Wall -fPIC -W -Waggregate-return \
		-Wcast-align -Wmissing-prototypes -Wnested-externs \
		-Wshadow -Wwrite-strings -pedantic -shared \
		-o lfs.so lfs.c -I${LUA_INCDIR}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/lfs.so ${LUA_MODLIBDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc/us/ && ${COPYTREE_SHARE} \* ${DOCSDIR})

.endif

.include <bsd.port.mk>
