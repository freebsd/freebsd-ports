# Created by: Lev A. Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	bin-msvcrt
PORTVERSION=	r${RUNTIMEVERSION}.a${APIVERSION:S/-/./}
CATEGORIES=	devel
MASTER_SITES=	SF/mingw/MinGW/Base/mingw-rt/mingwrt-${RUNTIMEVERSION}:runtime \
		SF/mingw/MinGW/Base/w32api/w32api-${APIVERSION:C/-.*$//}:api
PKGNAMEPREFIX=	mingw32-
DISTFILES=	mingwrt-${RUNTIMEVERSION}-mingw32-dev${EXTRACT_SUFX}:runtime \
		mingwrt-${RUNTIMEVERSION}-mingw32-dll${EXTRACT_SUFX}:runtime \
		w32api-${APIVERSION}-mingw32-dev${EXTRACT_SUFX:S/.gz$/.lzma/}:api
DIST_SUBDIR=	mingw

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Headers and Libraries for Windows cross-development

CONFLICTS=	mingw-bin-msvcrt-*

RUNTIMEVERSION=	3.20
APIVERSION=	3.17-2

NO_MTREE=	yes
NO_WRKSUBDIR=	yes

.if defined(INSTALL_AS_USER)
MAKE_ARGS+=	INSTALL_AS_USER=yes
.endif

NO_STAGE=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
