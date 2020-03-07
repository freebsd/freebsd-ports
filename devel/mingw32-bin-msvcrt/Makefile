# Created by: Lev A. Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	bin-msvcrt
PORTVERSION=	r${RUNTIMEVERSION:S/-/./}.a${APIVERSION:S/-/./}
CATEGORIES=	devel
MASTER_SITES=	SF/mingw/MinGW/Base/mingw-rt/mingwrt-${RUNTIMEVERSION:C/-.*$//}:runtime \
		SF/mingw/MinGW/Base/w32api/w32api-${APIVERSION:C/-.*$//}:api
PKGNAMEPREFIX=	mingw32-
DISTFILES=	mingwrt-${RUNTIMEVERSION}-mingw32-dev.tar.lzma:runtime \
		mingwrt-${RUNTIMEVERSION}-mingw32-dll.tar.lzma:runtime \
		w32api-${APIVERSION}-mingw32-dev.tar.lzma:api
DIST_SUBDIR=	mingw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Headers and Libraries for Windows cross-development

CONFLICTS=	mingw-bin-msvcrt-[0-9]*

USES=		tar:xz

RUNTIMEVERSION=	4.0.3-1
APIVERSION=	4.0.3-1

NO_MTREE=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
