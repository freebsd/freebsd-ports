# New ports collection makefile for:	pykawari
# Date created:				23 Jan 2004
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME=	pykawari
PORTVERSION=	8.1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kawari
DISTNAME=	kawari-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.lzh

PATCH_SITES=	http://rinakusu.at.infoseek.co.jp/
PATCHFILES=	kawari-810-py-module.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Pykawari is a real kawari8 module for ninix-aya

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha
RUN_DEPENDS=	ninix:${PORTSDIR}/games/ninix-aya

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xfqw=${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty

PLIST_SUB=	LOCALBASE=${LOCALBASE}

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/kawari-${PORTVERSION:S/.//g}
CFLAGS+=	${PTHREAD_CFLAGS}

do-build:
	(cd ${WRKSRC}/build/src; ${GMAKE} -f gcc.mak PYTHONBASE=${PYTHONBASE} PYTHON_VERSION=${PYTHON_VERSION})

do-install:
	${MKDIR} ${PREFIX}/share/kawari
	${TAR} -cf - document license.txt readme.1st build/build.txt -C ${WRKSRC} | ${TAR} -xvpf - -C ${PREFIX}/share/kawari
	${LN} ${WRKSRC}/build/mach/freebsd/libshiori.so ${WRKSRC}/build/mach/freebsd/_kawari8.so
	${MKDIR} ${PREFIX}/libexec/ninix
	${INSTALL_PROGRAM} ${WRKSRC}/build/mach/freebsd/_kawari8.so ${PREFIX}/libexec/ninix

.include <bsd.port.mk>
