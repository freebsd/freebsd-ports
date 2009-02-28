# New ports collection makefile for:	ophoto
# Date created:				Sat Mar 16 2002
# Whom:					Bob Withrow <witr@rwwa.com>
#
# $FreeBSD$
#

PORTNAME=	ophoto
PORTVERSION=	0.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.fromme.com/o/ophoto/
DISTNAME=	ophoto

MAINTAINER=	ports@FreeBSD.org
COMMENT=	USB support for Kodak DC240 and DC280 cameras under FreeBSD

ALL_TARGET=	ophoto
PLIST_FILES=	bin/ophoto

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ophoto ${PREFIX}/bin

.include <bsd.port.mk>
