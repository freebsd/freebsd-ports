PORTNAME=	catapult
PORTVERSION=	18.0
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/openMSX/openMSX/releases/download/RELEASE_${PORTVERSION:S/./_/g}/
DISTNAME=	openmsx-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for openMSX
WWW=		https://openmsx.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL.txt

BUILD_DEPENDS=	openmsx:emulators/openmsx
RUN_DEPENDS=	openmsx:emulators/openmsx

USES=		gmake pkgconfig python gnome
USE_GNOME+=	libxml2
USE_WX=		3.0
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

OPTIONS_DEFINE= DEBUG DOCS

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

.include <bsd.port.mk>
