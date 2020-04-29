# $FreeBSD$

PORTNAME=	libretro-desmume2015
PORTVERSION=	0.20200313
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
GH_TAGNAME=	93d5789

PLIST_FILES=	libexec/libretro/desmume2015_libretro.so

MAKEFILE=	Makefile.freebsd

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	${INSTALL_LIB} $$(find ${WRKSRC}/${COREDIR}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro;

.include <bsd.port.mk>
