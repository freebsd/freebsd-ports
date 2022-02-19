PORTNAME=	libtexluajit
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	LuaJIT library for TeXLive

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LuaJIT-src/COPYRIGHT

BROKEN_aarch64=	Does not configure: error: Sorry, cannot preprocess lj_arch.h
BROKEN_mips=	Does not configure: error: Sorry, cannot preprocess lj_arch.h
BROKEN_mips64=	Does not configure: error: Sorry, cannot preprocess lj_arch.h
BROKEN_powerpc64=	Does not build: uninitialized constant Config (NameError)
BROKEN_riscv64=	Does not configure: error: Sorry, cannot preprocess lj_arch.h
BROKEN_sparc64=	Does not configure: error: Sorry, cannot preprocess lj_arch.h

USES=		libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_TEX=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux libs/luajit
WRKSRC=		${WRKDIR}/${DISTNAME}/libs/luajit

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USES+=		compiler:gcc-c++11-lib
.endif

.include <bsd.port.mk>
