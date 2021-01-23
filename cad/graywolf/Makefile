# $FreeBSD$

PORTNAME=	graywolf
DISTVERSION=	0.1.6-4
DISTVERSIONSUFFIX=	-gf47937b
CATEGORIES=	cad

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES+=	af606a0e8c6f693448978a300e5603fd5a8f2aef.patch:-p1 # https://github.com/rubund/graywolf/pull/41

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fork of TimberWolf, a placement tool in VLSI design

LICENSE=	GPLv2

BROKEN_aarch64=	Fails to link: missing sbrk

LIB_DEPENDS=	libgsl.so:math/gsl
TEST_DEPENDS=	bash:shells/bash \
		rsync:net/rsync

USES=		cmake compiler:c11 pkgconfig shebangfix xorg
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rubund

SHEBANG_GLOB=	*.sh

USE_GCC=	any # lots of obviously incorrect C where clang fails, which gcc nevertheless magically finds a way to compile

CFLAGS+=	-fcommon

TEST_TARGET=	test # most tests crash

.include <bsd.port.mk>
