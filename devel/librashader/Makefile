PORTNAME=	librashader
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bsdcode@disroot.org
COMMENT=	RetroArch shaders for all
WWW=		https://github.com/SnowflakePowered/librashader

LICENSE=	GPLv3 MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-GPL.md
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	patchelf>0:sysutils/patchelf

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	SnowflakePowered
GH_TAGNAME=	${DISTNAME}
USE_LDCONFIG=	yes

CARGO_FEATURES=		--no-default-features runtime-opengl runtime-vulkan \
			stable
CARGO_BUILD_ARGS=	--package librashader-capi
CARGO_TEST=		no

OPTIONS_DEFINE=	DOCS EXAMPLES

# required ABI bump is always mentioned in the release notes
_ABI=		2

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/pkg/librashader.pc

post-build:
	patchelf --set-soname librashader.so.${_ABI} ${CARGO_TARGET_DIR}/*/liblibrashader_capi.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/librashader
	${INSTALL_DATA} ${WRKSRC}/include/librashader_ld.h \
		${STAGEDIR}${PREFIX}/include/librashader
	${INSTALL_DATA} ${WRKSRC}/include/librashader.h \
		${STAGEDIR}${PREFIX}/include/librashader
	${INSTALL_DATA} ${CARGO_TARGET_DIR}/*/liblibrashader_capi.a \
		${STAGEDIR}${PREFIX}/lib/librashader.a
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/liblibrashader_capi.so \
		${STAGEDIR}${PREFIX}/lib/librashader.so.${_ABI}
	${RLN} ${STAGEDIR}${PREFIX}/lib/librashader.so.${_ABI} ${STAGEDIR}${PREFIX}/lib/librashader.so
	${INSTALL_DATA} ${WRKSRC}/pkg/librashader.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BROKEN_SHADERS.md \
		${WRKSRC}/MIGRATION-ABI2.md \
		${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/include/README.md \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
