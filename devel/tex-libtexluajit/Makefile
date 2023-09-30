PORTNAME=	libtexluajit
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	LuaJIT library for TeXLive

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LuaJIT-src/COPYRIGHT

BROKEN_mips=	Does not configure: error: Sorry, cannot preprocess lj_arch.h
BROKEN_mips64=	Does not configure: error: Sorry, cannot preprocess lj_arch.h
BROKEN_powerpc64=	Does not build: uninitialized constant Config (NameError)
BROKEN_riscv64=	Does not configure: error: Sorry, cannot preprocess lj_arch.h

USES=		compiler libtool pathfix pkgconfig tar:xz tex
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux libs/luajit
WRKSRC=		${WRKDIR}/${DISTNAME}/libs/luajit

.include <bsd.port.pre.mk>

.if ${ARCH:Mpowerpc*} && ${COMPILER_VERSION} < 140
BUILD_DEPENDS+= as:devel/binutils
CFLAGS+=        -fno-integrated-as
.endif

.include <bsd.port.post.mk>
