# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	angelscript
PORTVERSION=	2.27.0
CATEGORIES=	lang
MASTER_SITES=	http://www.angelcode.com/angelscript/sdk/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	AngelCode Scripting Library

LICENSE=	ZLIB

MAKEFILE=	makefile
MAKE_ARGS=	LOCAL=${PREFIX}
USES=		gmake zip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/sdk/angelscript/projects/gnuc/

PLIST_FILES=	include/angelscript.h

OPTIONS_SINGLE=	TYPE
OPTIONS_SINGLE_TYPE=	STATIC SHARED
STATIC_DESC=		Build static library
SHARED_DESC=		Build shared library
OPTIONS_DEFAULT=	STATIC

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHARED}
LIB_VERSION=	2
MAKE_ARGS+=	SHARED=1 VERSION=${LIB_VERSION}
PLIST_FILES+=	lib/libangelscript.so.${LIB_VERSION} \
		lib/libangelscript-${LIB_VERSION}.so \
		lib/libangelscript.so

.else
PLIST_FILES+=	lib/libangelscript.a
.endif

.include <bsd.port.mk>
