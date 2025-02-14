PORTNAME=	tbox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.6
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Glib-like multi-platform c library
WWW=		https://docs.tboox.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		compiler:features gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tboox
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--demo=no \
		--generator=gmake \
		--kind=shared \
		--make=${MAKE_CMD} \
		--small=no \
		--toolchain=${CHOSEN_COMPILER_TYPE}
MAKEFILE=	makefile

.include <bsd.port.mk>
