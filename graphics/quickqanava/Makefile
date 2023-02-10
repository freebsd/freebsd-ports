PORTNAME=	quickqanava
DISTVERSION=	2.2.0
CATEGORIES=	graphics

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Library for QML-based Graph Visualisation
WWW=		https://cneben.github.io/QuickQanava/index.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/licence.txt

USES=		cmake compiler:c++14-lang qt:5
USE_QT=		core declarative gui network quickcontrols2 \
		buildtools:build qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	cneben
GH_PROJECT=	QuickQanava

post-stage:
	${RMDIR} ${STAGEDIR}/${PREFIX}/${QT_QMLDIR_REL}/QuickQanava/gtpo
	${RMDIR} ${STAGEDIR}/${PREFIX}/${QT_QMLDIR_REL}/QuickQanava/bezier/include
	${RMDIR} ${STAGEDIR}/${PREFIX}/${QT_QMLDIR_REL}/QuickQanava/bezier

.include <bsd.port.mk>
