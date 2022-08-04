PORTNAME=	vipack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	devel

MAINTAINER=	antranigv@freebsd.am
COMMENT=	Vishap package manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: voc is not yet available for powerpc64

BUILD_DEPENDS=	voc:lang/voc
RUN_DEPENDS=	git:devel/git

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	vishaps
GH_TUPLE=	norayr:Internet:4b33066:Internet/dps/Internet \
		norayr:lists:1fc8f0f:lists/dps/lists \
		norayr:opts:cc882ee:opts/dps/opts \
		norayr:time:c17a1c7:time/dps/time

MAKEFILE=	makefile_freebsd

PLIST_FILES=	bin/vipack

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
