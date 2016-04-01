# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	plee-the-bear
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Plee%20the%20Bear/${PORTVERSION:R}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D platform jump and run game

LICENSE=	GPLv2 CCbySA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbySA3=	Attribution-ShareAlike 3.0 Unported
LICENSE_FILE_CCbySA3=	${WRKSRC}/CCPL
LICENSE_PERMS_CCbySA3=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libclaw_application.so:devel/libclaw

USE_SDL=	sdl mixer
USE_GL=		gl glu
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

# gettext dep is unconditional; NLS option just disables translations install
USES=		cmake gettext
CMAKE_ARGS=	-Dlibclaw_DIR="${LOCALBASE}/share/libclaw/cmake" \
		-DBEAR_NO_EDITOR=YES

PORTDATA=	*

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/CMakeLists.txt

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|locale||' \
		${WRKSRC}/bear-factory/desktop/CMakeLists.txt \
		${WRKSRC}/bear-engine/desktop/CMakeLists.txt \
		${WRKSRC}/plee-the-bear/desktop/CMakeLists.txt

.include <bsd.port.mk>
