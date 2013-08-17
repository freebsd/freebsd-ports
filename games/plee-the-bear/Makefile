# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	plee-the-bear
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Plee%20the%20Bear/${PORTVERSION:R}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D platform jump and run game

LICENSE=	GPLv2 CCbySA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbySA3=Attribution-ShareAlike 3.0 Unported
LICENSE_FILE_CCbySA3=${WRKSRC}/CCPL
LICENSE_PERMS_CCbySA3=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man
LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost-libs \
		claw_application:${PORTSDIR}/devel/libclaw

USE_SDL=	sdl mixer
USE_GL=		gl glu
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_GCC=	yes

USES=		cmake
CMAKE_ARGS=	-Dlibclaw_DIR="${LOCALBASE}/share/libclaw/cmake" \
		-DBEAR_NO_EDITOR=YES

MAN6=		plee-the-bear.6 running-bear.6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/CMakeLists.txt
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|locale||' \
		${WRKSRC}/bear-engine/desktop/CMakeLists.txt \
		${WRKSRC}/plee-the-bear/desktop/CMakeLists.txt
.endif

.include <bsd.port.mk>
