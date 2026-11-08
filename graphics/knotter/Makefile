PORTNAME=	knotter
DISTVERSION=	0.9.6-20230206
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/yuri:patches # Qt6 patch, upstreamed https://gitlab.com/mattbas/Knotter/-/work_items/164
DISTFILES=	${PORTNAME}-${DISTVERSION}-qt6.tgz:patches # Qt6 patch, upstreamed https://gitlab.com/mattbas/Knotter/-/work_items/164

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive designer for Celtic knots
WWW=		https://gitlab.com/mattbas/Knotter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang desktop-file-utils gl qt:6
USE_QT=		base declarative svg tools:build
USE_GL=		opengl

USE_GITLAB=	yes
GL_ACCOUNT=	mattbas
GL_PROJECT=	Knotter
GL_TAGNAME=	fb8f1457c42d40df523860bb1cda55eca609f3b9

GL_TUPLE=	mattbas:CMake-Lib:6dd5afe4059899b47dbe0a7e2b940b1af41a59f6:mattbas_CMake_Lib/cmake \
		mattbas:Qt-Color-Widgets:450e54570a6f96b2d90960c3c62f7111bbc147e9:mattbas_Qt_Color_Widgets/src/widgets/color \
		mattbas:Qt-Extended-TabWidget:77cffc0714f9690d5627eaf6bd9b86b560f24066:mattbas_Qt_Extended_TabWidget/src/widgets/tabwidget \
		mattbas:Qt-History-LineEdit:fd37e87bb790d87c709a3234b8a0d8eedbb04031:mattbas_Qt_History_LineEdit/src/widgets/history_line_edit \
		mattbas:Qt-KeySequence-Widget:55faa8665c24bdc709582adb404401a909fc8c0c:mattbas_Qt_KeySequence_Widget/src/widgets/keysequence_widget \
		mattbas:Qt-Toolbar-Editor:dff8fa080f5fa596517c4d4c9523c7a968f13766:mattbas_Qt_Toolbar_Editor/src/widgets/toolbar_editor

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://gitlab.com/mattbas/Knotter/-/work_items/163

post-patch: # patch for Qt6 using the downloaded patch
	@cd ${WRKSRC} && \
		${PATCH} < ${WRKDIR}/patches/knotter-${DISTVERSION}-qt6.patch

.include <bsd.port.mk>
