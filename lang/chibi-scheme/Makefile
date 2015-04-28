# Created by: Tobias Kortkamp <tobias.kortkamp@gmail.com>
# $FreeBSD$

PORTNAME=	chibi-scheme
PORTVERSION=	0.7.2
CATEGORIES=	lang

MAINTAINER=	tobias.kortkamp@gmail.com
COMMENT=	Minimal Scheme implementation for use as a C extension language

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	norton

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ARGS=	MODDIR=${LOCALBASE}/lib/chibi \
		PKGCONFDIR=${LOCALBASE}/libdata/pkgconfig

.include <bsd.port.mk>
