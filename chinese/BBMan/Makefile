# New ports collection makefile for:    zh-BBMan
# Date created:		24 July 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	BBMan
PORTVERSION=	1.7.7.5
CATEGORIES=	chinese net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bbman
DISTNAME=	BBMan-src-v1-7-7-5
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@freebsd.org
COMMENT=	BBMan is a BBS client for X Window System

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/BBMan
USE_X_PREFIX=	yes

do-build:
		cd ${WRKSRC} && g++ main.cpp `wxgtk2-2.4-config --libs --cxxflags` -I${LOCALBASE}/include -O2 -o BBMan

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/BBMan ${PREFIX}/bin/BBMan

.include <bsd.port.mk>
