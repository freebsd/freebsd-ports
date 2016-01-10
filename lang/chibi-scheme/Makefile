# Created by: Tobias Kortkamp <tobias.kortkamp@gmail.com>
# $FreeBSD$

PORTNAME=	chibi-scheme
PORTVERSION=	0.7.3
CATEGORIES=	lang

MAINTAINER=	t@tobik.me
COMMENT=	Minimal Scheme implementation for use as a C extension language

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	ashinn

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ARGS+=	MODDIR=${LOCALBASE}/lib/chibi \
		MANDIR=${LOCALBASE}/man/man1 \
		INSTALL_BIN="${INSTALL} -s" \
		PKGCONFDIR=${LOCALBASE}/libdata/pkgconfig

.include <bsd.port.mk>
