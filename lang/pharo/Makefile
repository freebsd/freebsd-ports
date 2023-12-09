PORTNAME=	pharo
DISTVERSION=	10.0.9
DISTVERSIONSUFFIX=	de76067
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://files.pharo.org/vm/pharo-spur64-headless/Linux-x86_64/source/
DISTNAME=	PharoVM-${DISTVERSION}-${DISTVERSIONSUFFIX}-Linux-x86_64-c-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smalltalk-inspired language and environment
WWW=		http://www.pharo.org/

LICENSE=	MIT

LIB_DEPENDS=	libffi.so:devel/libffi \
		libgit2.so:devel/libgit2 \
		libcairo.so:graphics/cairo \
		libfreetype.so:print/freetype2 \
		libpixman-1.so:x11/pixman \
		libpng.so:graphics/png \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake ssl
CMAKE_ARGS=	-DFLAVOUR=CoInterpreter \
		-DPHARO_BIN_LOCATION=${PREFIX}/libexec/pharo10 \
		-DGENERATED_SOURCE_DIR=.
CMAKE_ON=	ALWAYS_INTERACTIVE BUILD_IS_RELEASE
CMAKE_OFF=	GENERATE_SOURCES BUILD_BUNDLE

WRKSRC=		${WRKDIR}/pharo-vm

USE_HCC=	yes
USE_SDL=	sdl image

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/pharo10
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pharo10
	cd ${WRKDIR}/.build/build/packaging/linux/bin && \
		${INSTALL_SCRIPT} pharo ${STAGEDIR}${PREFIX}/bin/pharo10
	cd ${WRKDIR}/.build/build/vm && \
		${INSTALL_PROGRAM} pharo ${STAGEDIR}${PREFIX}/libexec/pharo10/pharo
	cd ${WRKDIR}/.build/build/vm && \
		${FIND} . -type f -name "*.so" | while read file; do \
		${INSTALL_LIB} $$file ${STAGEDIR}${PREFIX}/lib/pharo10/$$file; \
		done

.include <bsd.port.mk>
