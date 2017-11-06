# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	angelscript
PORTVERSION=	2.29.0
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.angelcode.com/angelscript/sdk/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	AngelCode Scripting Library

LICENSE=	ZLIB

BROKEN_aarch64=		Does not build: invokes x86 asm
BROKEN_powerpc64=	Does not build: invokes x86 asm
BROKEN_sparc64=		Does not build: invokes x86 asm

MAKEFILE=	makefile
MAKE_ARGS=	LOCAL=${STAGEDIR}${PREFIX}
USES=		alias gmake zip compiler:c++0x
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/sdk/angelscript/projects/gnuc/

PLIST_FILES=	include/angelscript.h \
		lib/libangelscript.a

.include <bsd.port.mk>
