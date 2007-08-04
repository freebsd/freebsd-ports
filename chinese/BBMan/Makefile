# New ports collection makefile for:    zh-BBMan
# Date created:		24 July 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	BBMan
PORTVERSION=	1.7.7.5
PORTREVISION=	4
CATEGORIES=	chinese net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME}-src-v${PORTVERSION:S,.,-,g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BBMan is a BBS client for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_WX=		2.4

PLIST_FILES=	bin/BBMan

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
USE_GCC=	3.3
.endif

.if ${ARCH} == ia64
BROKEN=		Hard-codes reference to libc_r
.endif

do-build:
	cd ${WRKSRC} && ${CXX} main.cpp `${WX_CONFIG} --libs --cxxflags` -I${LOCALBASE}/include ${CFLAGS} -o BBMan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/BBMan ${PREFIX}/bin/BBMan

.include <bsd.port.post.mk>
