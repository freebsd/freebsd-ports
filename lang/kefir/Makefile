PORTNAME=	kefir
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	lang devel
MASTER_SITES=	https://git.sr.ht/~jprotopopov/kefir/archive/${DISTVERSIONFULL}.tar.gz?dummy=/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	C17/C23 compiler
WWW=		https://kefir.protopopov.lv/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	compiler targets amd64 only right now

BUILD_DEPENDS=	as:devel/binutils \
		grealpath:sysutils/coreutils
RUN_DEPENDS=	as:devel/binutils
TEST_DEPENDS=	bash:shells/bash

USES=		gmake
USE_LDCONFIG=	yes
TEST_TARGET= 	test
MAKE_ARGS=	prefix=${PREFIX}
.if "${WITH_DEBUG}" == "yes"
MAKE_ARGS+=	PROFILE=debug
.endif

.include <bsd.port.mk>
