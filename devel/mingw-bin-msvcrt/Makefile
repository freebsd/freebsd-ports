# New ports collection makefile for: mingw-bin-msvcrt
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	bin-msvcrt
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mingw
PKGNAMEPREFIX=	mingw-
DISTFILES=	mingw-runtime-${PORTVERSION}${EXTRACT_SUFX} \
		w32api-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	mingw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Headers and Libraries for Windows cross-development

CONFLICTS=	mingw32-bin-msvcrt-*

NO_MTREE=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
STRIP=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mingwm10.dll ${PREFIX}/bin
	${MKDIR} ${PREFIX}/i386-mingw32msvc/lib
	${MKDIR} ${PREFIX}/i386-mingw32msvc/include/sys
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/i386-mingw32msvc/lib/
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/i386-mingw32msvc/include
	${INSTALL_DATA} ${WRKSRC}/include/sys/* ${PREFIX}/i386-mingw32msvc/include/sys/
	${INSTALL_DATA} ${WRKSRC}/mingw32/lib/* ${PREFIX}/i386-mingw32msvc/lib/
	${INSTALL_DATA} ${WRKSRC}/mingw32/include/* ${PREFIX}/i386-mingw32msvc/include

.include <bsd.port.mk>
