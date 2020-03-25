# $FreeBSD$

PORTNAME=	graywolf
DISTVERSION=	0.1.6-3
DISTVERSIONSUFFIX=	-g6c5e24f
PORTREVISION=	1
CATEGORIES=	cad

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES+=	af606a0e8c6f693448978a300e5603fd5a8f2aef.patch:-p1 # https://github.com/rubund/graywolf/pull/41

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fork of TimberWolf, a placement tool in VLSI design

LICENSE=	GPLv2

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		cmake pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	rubund
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

USE_GCC=	any # lots of obviously incorrect C where clang fails, which gcc nevertheless magically finds a way to compile

.include <bsd.port.mk>
