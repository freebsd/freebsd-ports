# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	catapult
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/openmsx/openmsx/${PORTVERSION}
DISTNAME=	openmsx-${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GUI for openMSX

LICENSE=	GPLv2

BUILD_DEPENDS=	openmsx:${PORTSDIR}/emulators/openmsx
RUN_DEPENDS=	openmsx:${PORTSDIR}/emulators/openmsx

OPTIONS_DEFINE=	DEBUG DOCS

USES=		gmake pkgconfig
USE_GCC=	yes
USE_CXXSTD=	gnu++0x
USE_GNOME=	gtk20 libxml2
USE_WX=		2.8+
USE_PYTHON_BUILD=yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	INSTALL_BASE="${STAGEDIR}${PREFIX}" \
		INSTALL_SHARE_DIR="${STAGEDIR}${DATADIR}" \
		INSTALL_DOC_DIR="${STAGEDIR}${DOCSDIR}" \
		CATAPULT_FLAVOUR="portbld" \
		CATAPULT_OPENMSX_BINARY="${LOCALBASE}/bin/openmsx" \
		CATAPULT_OPENMSX_SHARE="${LOCALBASE}/share/openmsx" \
		CATAPULT_NO_DESKTOP_HOOKS="true" \
		SYMLINK_FOR_BINARY="false" \
		PYTHON="${PYTHON_CMD}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-DDEBUG
CATAPULT_STRIP=	false
.else
CFLAGS+=	-DNDEBUG
CATAPULT_STRIP=	true
.endif

post-extract:
	${CP} ${WRKSRC}/build/platform-freebsd.mk \
		${WRKSRC}/build/platform-dragonfly.mk

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's|$$(INSTALL_BASE)|${DATADIR}|' \
		${WRKSRC}/build/info2code.mk
	@${REINPLACE_CMD} '/-Wno-literal/s|^CXXFLAGS|#CXXFLAGS| ; \
		 /--cxx/s|^CXX|#CXX| ; \
		 /COMPILE=/s|g++|$$(CXX)| ; \
		 s|@$$(CXX)|$$(CXX)|' ${WRKSRC}/build/main.mk
	@${REINPLACE_CMD} 's|wx-config --|${WX_CONFIG:T} --|g' \
		${WRKSRC}/build/probe.mk
	@${REINPLACE_CMD} '/^Exec/s|%INSTALL_BASE%|${PREFIX}| ; \
		 /^Icon/s|%INSTALL_BASE%|${DATADIR}| ; \
		 /^DocPath/s|%INSTALL_BASE%/doc|${DOCSDIR}|' \
		${WRKSRC}/desktop/openMSX-Catapult.desktop
	@${ECHO_CMD} > ${WRKSRC}/build/flavour-portbld.mk
	@${ECHO_CMD} 'CXXFLAGS+=${CXXFLAGS}' \
		>> ${WRKSRC}/build/flavour-portbld.mk
	@${ECHO_CMD} 'LINK_FLAGS+=${LDFLAGS}' \
		>> ${WRKSRC}/build/flavour-portbld.mk
	@${ECHO_CMD} 'CATAPULT_STRIP:=${CATAPULT_STRIP}' \
		>> ${WRKSRC}/build/flavour-portbld.mk

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/resources/icons
	@${INSTALL_DATA} ${WRKSRC}/src/catapult.xpm \
		${STAGEDIR}${DATADIR}/resources/icons
	@cd ${WRKSRC}/desktop && ${INSTALL_DATA} openMSX-Catapult.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.post.mk>
