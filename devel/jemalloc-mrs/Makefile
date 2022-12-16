PORTNAME=	jemalloc-mrs
DISTVERSION=	20221216
CATEGORIES=	devel

MAINTAINER=	nfilardo@microsoft.com
COMMENT=	jemalloc modified for use with devel/mrs
WWW=		https://github.com/ctsrd-cheri/mrs

LICENSE=	BSD2CLAUSE
LICENSE_COMB=	single
LICENSE_FILE=	${WRKSRC}/jemalloc/COPYING

ONLY_FOR_ARCHS=	aarch64c riscv64c

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	mrs
GH_TAGNAME=	d77220664c077d0568019eeb5f4d1d1dacea5343

ALL_TARGET=	jemalloc

do-install:
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/libjemalloc.so \
		${STAGEDIR}${PREFIX}/lib/libjemalloc-mrs.so

.include <bsd.port.mk>
