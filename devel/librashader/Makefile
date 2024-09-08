PORTNAME=	librashader
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
CATEGORIES=	devel

MAINTAINER=	bsdcode@disroot.org
COMMENT=	RetroArch shaders for all
WWW=		https://github.com/SnowflakePowered/librashader

LICENSE=	GPLv3 MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-GPL.md
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	patchelf:sysutils/patchelf \
		rust-nightly>0:lang/rust-nightly

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	SnowflakePowered
GH_TAGNAME=	${DISTNAME}
USE_LDCONFIG=	yes

CARGO_BUILDDEP=		no
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no
CARGO_TARGET_DIR=	${WRKSRC}/target

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES

DEBUG_VARS=	_PROFILE=debug
DEBUG_VARS_OFF=	_PROFILE=release

# https://github.com/SnowflakePowered/librashader#versioning
# grep '#define LIBRASHADER_CURRENT_ABI' ${WRKSRC}/include/librashader.h | cut -d' ' -f3
_ABI=		1

_OUT=		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/${_PROFILE}

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/pkg/librashader.pc

do-build:
	${CARGO_CARGO_RUN} run -p librashader-build-script -- --profile \
		${_PROFILE} --target ${CARGO_BUILD_TARGET}
	patchelf --set-soname librashader.so.${_ABI} ${_OUT}/librashader.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/librashader
	${INSTALL_DATA} ${WRKSRC}/include/librashader_ld.h \
		${STAGEDIR}${PREFIX}/include/librashader
	${INSTALL_DATA} ${_OUT}/librashader.h \
		${STAGEDIR}${PREFIX}/include/librashader
	${INSTALL_DATA} ${_OUT}/librashader.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${_OUT}/librashader.so \
		${STAGEDIR}${PREFIX}/lib/librashader.so.${_ABI}
	${LN} -s librashader.so.${_ABI} ${STAGEDIR}${PREFIX}/lib/librashader.so
	${INSTALL_DATA} ${WRKSRC}/pkg/librashader.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BROKEN_SHADERS.md \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/include/README.md \
		${STAGEDIR}${EXAMPLESDIR}/README.md

.include <bsd.port.mk>
