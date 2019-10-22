# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	angelscript
PORTVERSION=	2.34.0
CATEGORIES=	lang
MASTER_SITES=	http://www.angelcode.com/angelscript/sdk/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ndowens04@gmail.com
COMMENT=	AngelCode Scripting Library

LICENSE=	ZLIB

BROKEN_aarch64=	Does not build: invokes x86 asm
BROKEN_sparc64=	Does not build: invokes x86 asm

USES=		alias compiler:c11 dos2unix gmake zip
USE_LDCONFIG=	yes

DOS2UNIX_FILES=	../../source/as_config.h

MAKE_ARGS=	CP_SYMLINK="${INSTALL_LIB}"

WRKSRC=		${WRKDIR}/sdk/angelscript/projects/gnuc/

PLIST_FILES=	include/angelscript.h \
		lib/libangelscript.a \
		lib/libangelscript.so \
		lib/libangelscript.so.${PORTVERSION}

.include <bsd.port.options.mk>
.if ${ARCH} == "i386"
pre-build:
	(cd ${WRKDIR}/sdk/angelscript/source && ${REINPLACE_CMD} -e 's|ifdef __OPTIMIZE__|if defined(__OPTIMIZE__) \&\&\ !defined(__clang__)|g' \
		-e 's,ifdef __OPTIMIZE__ifdef __OPTIMIZE__,,g' *.cpp)
.endif

.include <bsd.port.mk>
