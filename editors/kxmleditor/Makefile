# New ports collection makefile for:	kxmleditor
# Date created:		15 July 2001
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kxmleditor
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	XML editor for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
