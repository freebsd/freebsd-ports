# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	catapult
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/openmsx/openmsx/${PORTVERSION}
DISTNAME=	openmsx-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for openMSX

LICENSE=	GPLv2

BUILD_DEPENDS=	openmsx:${PORTSDIR}/emulators/openmsx
LIB_DEPENDS=	mspack:${PORTSDIR}/archivers/libmspack \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		jbig:${PORTSDIR}/graphics/jbigkit \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	openmsx:${PORTSDIR}/emulators/openmsx

OPTIONS_DEFINE=	DEBUG DOCS

USE_GNOME=	gdkpixbuf2 glib20 gtk20 libxml2
USE_WX=		2.6+
USE_PYTHON_BUILD=yes
USES=		gettext gmake iconv
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp \
		xext xfixes xi xinerama xrandr xrender xxf86vm
MAKEFILE=	GNUmakefile
MAKE_ARGS=	INSTALL_BASE="${PREFIX}" \
		INSTALL_SHARE_DIR="${DATADIR}" \
		CATAPULT_FLAVOUR="portbld" \
		CATAPULT_OPENMSX_BINARY="${LOCALBASE}/bin/openmsx" \
		CATAPULT_OPENMSX_SHARE="${LOCALBASE}/share/openmsx" \
		SYMLINK_FOR_BINARY="false"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=	INSTALL_DOC_DIR="${DOCSDIR}"
.else
# Use dummy target rather than rewriting makefile
MAKE_ARGS+=	INSTALL_DOC_DIR="${WRKSRC}/dummy"
.endif

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-DDEBUG
CATAPULT_STRIP=	false
.else
CFLAGS+=	-DNDEBUG
CATAPULT_STRIP=	true
.endif

post-patch:
	@${REINPLACE_CMD} 's|INSTALL_BASE|INSTALL_SHARE_DIR|' \
		${WRKSRC}/build/info2code.mk
	@${REINPLACE_CMD} '/--no-strict-aliasing/s|^CXXFLAGS|#CXXFLAGS| ; \
		 /--cxx/s|^CXX|#CXX| ; \
		 s|@$$(CXX)|$$(CXX)|' ${WRKSRC}/build/main.mk
	@${REINPLACE_CMD} 's|wx-config --|${WX_CONFIG:T} --|g' \
		${WRKSRC}/build/probe.mk
	@${ECHO_CMD} > ${WRKSRC}/build/flavour-portbld.mk
	@${ECHO_CMD} 'CXXFLAGS+=${CXXFLAGS}' \
		>> ${WRKSRC}/build/flavour-portbld.mk
	@${ECHO_CMD} 'CATAPULT_STRIP:=${CATAPULT_STRIP}' \
		>> ${WRKSRC}/build/flavour-portbld.mk

.include <bsd.port.mk>
