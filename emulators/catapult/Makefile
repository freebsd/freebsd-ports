# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	catapult
PORTVERSION=	0.13.0
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/openMSX/openMSX/releases/download/RELEASE_${PORTVERSION:S/./_/g}/
DISTNAME=	openmsx-${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GUI for openMSX

LICENSE=	GPLv2

BUILD_DEPENDS=	openmsx:emulators/openmsx
RUN_DEPENDS=	openmsx:emulators/openmsx

OPTIONS_DEFINE=	DEBUG DOCS

USES=		gmake pkgconfig python:2.7,build
USE_GCC=	yes
USE_CXXSTD=	gnu++0x
USE_GNOME=	gtk20 libxml2
USE_WX=		2.8
MAKEFILE=	GNUmakefile
MAKE_ARGS=	INSTALL_BASE="${PREFIX}" \
		INSTALL_SHARE_DIR="${DATADIR}" \
		INSTALL_DOC_DIR="${DOCSDIR}" \
		CATAPULT_FLAVOUR="portbld" \
		CATAPULT_OPENMSX_BINARY="${LOCALBASE}/bin/openmsx" \
		CATAPULT_OPENMSX_SHARE="${LOCALBASE}/share/openmsx" \
		CATAPULT_NO_DESKTOP_HOOKS="true" \
		SYMLINK_FOR_BINARY="false" \
		PYTHON="${PYTHON_CMD}"

MAKE_JOBS_UNSAFE=	yes

BROKEN_aarch64=	fails to link: fails to detect libxml2 even though it is installed
BROKEN_armv6=	fails to link: fails to detect libxml2 even though it is installed
BROKEN_armv7=	fails to link: fails to detect libxml2 even though it is installed

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
	${MKDIR} ${STAGEDIR}${DATADIR}/resources/icons
	${INSTALL_DATA} ${WRKSRC}/src/catapult.xpm \
		${STAGEDIR}${DATADIR}/resources/icons
	cd ${WRKSRC}/desktop && ${INSTALL_DATA} openMSX-Catapult.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.post.mk>
