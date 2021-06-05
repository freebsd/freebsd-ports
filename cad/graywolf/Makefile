PORTNAME=	graywolf
DISTVERSION=	0.1.6-4
DISTVERSIONSUFFIX=	-gf47937b
PORTREVISION=	2
CATEGORIES=	cad

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	af606a0e8c6f693448978a300e5603fd5a8f2aef.patch:-p1 # https://github.com/rubund/graywolf/pull/41
PATCHFILES+=	2b23616f26d8f9a9fa03010322fa967a2dc204e3.patch:-p1 \
		b0692b44dfc21ded1ad61c8a2e47d262d14ebabe.patch:-p1 \
		9b6a45849ddf1d48b7d0bffa914919a785f6db44.patch:-p1 \
		56698bb3178b606dec6749cf1f893acceca4ca62.patch:-p1 \
		0740f436419a9cce323936e0dec2355dde59a97e.patch:-p1 \
		a9a092d9c2dab31993bc2955c5ed730c9234df29.patch:-p1 # https://github.com/rubund/graywolf/pull/48

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

USE_GCC=	yes # lots of obviously incorrect C where clang fails, which gcc nevertheless magically finds a way to compile

CFLAGS+=	-fcommon

TEST_TARGET=	test

.include <bsd.port.mk>
