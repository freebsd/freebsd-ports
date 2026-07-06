PORTNAME=	tbox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/tboox/tbox/commit/
PATCHFILES=	d9e08d25be440062b30c4fe31bf602fd048ab354.diff:-p1

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Glib-like multi-platform c library
WWW=		https://tboox.top/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		compiler:features gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tboox
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--charset=y \
		--demo=no \
		--float=y \
		--force_utf8=y \
		--generator=gmake \
		--hash=y \
		--kind=shared \
		--make=${MAKE_CMD} \
		--small=no \
		--toolchain=${CHOSEN_COMPILER_TYPE}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
