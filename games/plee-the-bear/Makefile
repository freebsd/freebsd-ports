# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	plee-the-bear
PORTVERSION=	0.6.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Plee%20the%20Bear/${PORTVERSION:R}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D platform jump and run game

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/CCPL

BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libclaw_application.so:devel/libclaw

BROKEN=		does not build with boost 1.62

# gettext dep is unconditional; NLS option just disables translations install
USES=		cmake gettext
CMAKE_ARGS=	-Dlibclaw_DIR="${LOCALBASE}/share/libclaw/cmake" \
		-DBEAR_NO_EDITOR=YES
USE_SDL=	sdl mixer
USE_GL=		gl glu
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

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
