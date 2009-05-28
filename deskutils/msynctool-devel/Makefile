# New ports collection makefile for:	msynctool-devel
# Date created:				11 June 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	msynctool
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A command line client for the OpenSync framework

LIB_DEPENDS=	opensync.1:${PORTSDIR}/devel/libopensync

CONFLICTS=	msynctool-0.2*

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
