# ex:ts=8
# New ports collection makefile for:	clip
# Date created:			Dec 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clip
PORTVERSION=	0.96
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.itk.ru/pub/clip/ \
		ftp://slavik.eu.org/apps/development/compilers/clip/ \
		ftp://ftp.linux.ru.net/mirrors/clip/
DISTNAME=	${PORTNAME}-prg-${PORTVERSION}-1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	local
MAKE_ENV=	HOME=${WRKDIR}

do-install:
	${CP} -R ${WRKDIR}/cliproot ${LOCALBASE}/clip

.include <bsd.port.mk>
