# New ports collection makefile for: mingw32-bin-msvcrt
# Date created:		24 Oct 2002
# Whom:                 Lev A. Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	bin-msvcrt
PORTVERSION=	r${RUNTIMEVERSION}.a${APIVERSION}
CATEGORIES=	devel
MASTER_SITES=	SF/mingw/MinGW%20Runtime/mingwrt-${RUNTIMEVERSION}:runtime \
		SF/mingw/MinGW%20API%20for%20MS-Windows/w32api-${APIVERSION}:api
PKGNAMEPREFIX=	mingw32-
DISTFILES=	mingwrt-${RUNTIMEVERSION}-mingw32-dev${EXTRACT_SUFX}:runtime \
		mingwrt-${RUNTIMEVERSION}-mingw32-dll${EXTRACT_SUFX}:runtime \
		w32api-${APIVERSION}-mingw32-dev${EXTRACT_SUFX}:api
DIST_SUBDIR=	mingw

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Headers and Libraries for Windows cross-development

CONFLICTS=	mingw-bin-msvcrt-*

RUNTIMEVERSION=	3.18
APIVERSION=	3.14

NO_MTREE=	yes
NO_WRKSUBDIR=	yes

.if defined(INSTALL_AS_USER)
MAKE_ARGS+=	INSTALL_AS_USER=yes
.endif

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
