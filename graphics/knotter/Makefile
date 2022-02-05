PORTNAME=	knotter
DISTVERSION=	0.9.6.20220205
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interactive designer for Celtic knots

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang desktop-file-utils gl qt:5
USE_QT=		core gui network printsupport script svg xml widgets \
		buildtools_build linguisttools_build qmake_build uitools_build
USE_GL=		gl

USE_GITLAB=	yes
GL_ACCOUNT=	mattbas
GL_PROJECT=	Knotter
GL_COMMIT=	9ce77e3e0507343a3b400c6806ab79b52b1ad596

GL_TUPLE=	mattbas:CMake-Lib:6dd5afe4059899b47dbe0a7e2b940b1af41a59f6:mattbas_CMake_Lib/cmake \
		mattbas:Qt-Color-Widgets:450e54570a6f96b2d90960c3c62f7111bbc147e9:mattbas_Qt_Color_Widgets/src/widgets/color \
		mattbas:Qt-Extended-TabWidget:77cffc0714f9690d5627eaf6bd9b86b560f24066:mattbas_Qt_Extended_TabWidget/src/widgets/tabwidget \
		mattbas:Qt-History-LineEdit:fd37e87bb790d87c709a3234b8a0d8eedbb04031:mattbas_Qt_History_LineEdit/src/widgets/history_line_edit \
		mattbas:Qt-KeySequence-Widget:55faa8665c24bdc709582adb404401a909fc8c0c:mattbas_Qt_KeySequence_Widget/src/widgets/keysequence_widget \
		mattbas:Qt-Toolbar-Editor:dff8fa080f5fa596517c4d4c9523c7a968f13766:mattbas_Qt_Toolbar_Editor/src/widgets/toolbar_editor

.include <bsd.port.mk>
