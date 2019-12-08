# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmpdclient
PORTVERSION=	2.17
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/libmpdclient/2/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API library for interfacing MPD

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson tar:xz

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes
DOXYGEN_IMPLIES=DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_MESON_TRUE=	documentation

.include <bsd.port.mk>
