# New ports collection makefile for:	xrot
# Date created:				Apr 2, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	xrot
PORTVERSION=	1.3.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.kobe-u.ac.jp/pub/Linux/packages/Vine/VinePlus/1.1/JG-0.9.1/sources/
MASTER_SITE_SUBDIR=	will

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A falling ball puzzle game for X

ALL_TARGET=	xrot
PLIST_FILES=	bin/xrot
WRKSRC=		${WRKDIR}/xrot
USE_IMAKE=	yes
USE_XPM=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrot ${PREFIX}/bin
	${CHOWN} root:games ${PREFIX}/bin/xrot
	${CHMOD} g+s ${PREFIX}/bin/xrot
	${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
