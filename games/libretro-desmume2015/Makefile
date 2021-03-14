# $FreeBSD$

PORTNAME=	libretro-desmume2015
PORTVERSION=	0.20210131
CATEGORIES=	games

MAINTAINER=	menelkir@itroll.org
COMMENT=	Port of Desmume to libretro based on Desmume SVN circa 2015

LICENSE=	GPLv2

BROKEN_aarch64=	fails to compile: invokes x86 assembler

USES=		compiler:c++11-lib gmake gl
USE_LDCONFIG=	yes
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	desmume2015
GH_TAGNAME=	d6128e6

PLIST_FILES=	lib/libretro/desmume2015_libretro.so

MAKEFILE=	Makefile.freebsd

.include <bsd.port.options.mk>

.if ${ARCH} != aarch64 || ${ARCH} != amd64 || !${ARCH:Marmv*} || ${ARCH} != i386
MAKE_ENV+=	DESMUME_JIT=0
.endif

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/desmume/desmume2015_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
