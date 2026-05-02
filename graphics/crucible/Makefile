PORTNAME=	crucible
DISTVERSION=	g20260429
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/ocochard/crucible/commit/
PATCHFILES=	2b898ed7107178224b451728f15672dc1733121d.patch:-p1 \
		384620d1fcb58cdb20a5594aac3d5a5844dfd757.patch:-p1

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Vulkan test suite
WWW=		https://gitlab.freedesktop.org/mesa/crucible

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		a2x:textproc/asciidoc \
		${PYTHON_PKGNAMEPREFIX}opencv-python-headless>0:graphics/py-opencv-python-headless@${PY_FLAVOR}
LIB_DEPENDS=	libpng.so:graphics/png \
		libxml2.so:textproc/libxml2 \
		libvulkan.so:graphics/vulkan-loader \
		libepoll-shim.so:devel/libepoll-shim

USES=		meson pkgconfig python:build

BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_TAGNAME=	1b6b04dfb0c4f94bf08b6b5cd0c3f4520da9bc6b

CFLAGS+=	-DCRUCIBLE_DATA_DIR=${DATADIR}/data

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/crucible ${STAGEDIR}${PREFIX}/bin/
.for m in 1 7
	${INSTALL_MAN} ${BUILD_WRKSRC}/doc/*.${m} ${STAGEDIR}${PREFIX}/share/man/man${m}/
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	cd ${BUILD_WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/data

.include <bsd.port.mk>
