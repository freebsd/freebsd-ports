# New ports collection makefile for:	kbear
# Date created:				Wed May 29 18:10:01 PDT 2002
# Whom:					Tilman Linneweh <tilman@arved.de>
#
# $FreeBSD$

PORTNAME=		kbear
PORTVERSION=		2.0.a.1
CATEGORIES=		ftp kde
MASTER_SITES= 		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= 	${PORTNAME}
DISTNAME=		${PORTNAME}-2.0alpha1

MAINTAINER=		freebsdports@arved.de

USE_KDELIBS_VER=	3
USE_BZIP2= 		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
