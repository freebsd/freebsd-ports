# Created by: ijliao
# $FreeBSD$

PORTNAME=	aqsis
PORTVERSION=	1.8.2
PORTREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Photorealistic rendering system

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	bison:devel/bison \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR \
		libboost_filesystem.so:devel/boost-libs \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	bash:shells/bash

BROKEN_sparc64=	Fails to build: cannot link with boost

LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		shared-mime-info shebangfix
USE_CXXSTD=	gnu++11
SHEBANG_FILES=	examples/*/*/*.sh \
		tools/neqsus/houdini/post.sh \
		distribution/linux/*.sh
USE_QT4=	opengl qmake_build moc_build rcc_build uic_build
PLIST_SUB+=	LIBVERS=${PORTVERSION:R}

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|examples_install_dir $${EXAMPLESDIR}|examples_install_dir ${PREFIX}/share/examples/${PORTNAME}|' \
		${WRKSRC}/examples/CMakeLists.txt

.if !${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -i '' -e '/add_subdirectory(examples)/d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
