# ex:ts=8
# New ports collection makefile for:	clip
# Date created:			Dec 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clip
PORTVERSION=	0.99
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.lastik.ru/clip/ \
		ftp://ftp.linux.ru.net/mirrors/clip/
DISTNAME=	${PORTNAME}-prg-${PORTVERSION}-3
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BROKEN=		"Incorrect pkg-plist"

USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	local
MAKE_ENV=	HOME=${WRKDIR}

do-install:
	${CP} -R ${WRKDIR}/cliproot ${LOCALBASE}/clip

.include <bsd.port.mk>
