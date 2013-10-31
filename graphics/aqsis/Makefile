# Created by: ijliao
# $FreeBSD$

PORTNAME=	aqsis
PORTVERSION=	1.8.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Photorealistic rendering system

LICENSE=	BSD GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libtiff.so:${PORTSDIR}/graphics/tiff

LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USES=		cmake:outsource desktop-file-utils shared-mime-info
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
