PORTNAME=	tbox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.8
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Glib-like multi-platform c library
WWW=		https://tboox.org/

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
