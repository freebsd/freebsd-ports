# New ports collection makefile for:	libopensync-plugin-python-devel
# Date created:				16 June 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libopensync-plugin-python
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Python plugin for the OpenSync framework

LIB_DEPENDS=	opensync.1:${PORTSDIR}/devel/libopensync

CONFLICTS=	libopensync-plugin-python-0.2*

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-Wno-dev

pre-patch:
	@${REINPLACE_CMD} -e "s|MESSAGE|# MESSAGE|" \
		${WRKSRC}/cmake/modules/MacroEnsureOutOfSourceBuild.cmake

.include <bsd.port.mk>
