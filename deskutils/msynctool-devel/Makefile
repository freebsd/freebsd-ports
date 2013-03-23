# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	msynctool
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command line client for the OpenSync framework

LIB_DEPENDS=	opensync.1:${PORTSDIR}/devel/libopensync

CONFLICTS=	msynctool-0.2*

USE_BZIP2=	yes
USES=		cmake
USE_PKGCONFIG=	build

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
