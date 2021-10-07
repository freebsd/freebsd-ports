PORTNAME=	quickqanava
PORTVERSION=	0.1
CATEGORIES=	graphics

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Library for QML-based Graph Visualisation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/licence.txt

USES=		cmake compiler:c++14-lang qt:5
USE_QT=		core declarative gui network quickcontrols2 \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	cneben
GH_PROJECT=	QuickQanava
GH_TAGNAME=	ab88d77ec62175b9fd499a154ffaf92f7bf23989

# There are no releases, even though the project is years old,
# and the site mentions "alpha, pre-1.0". Once there's an actual
# release, can switch to DISTVERSION and release-tarballs.

.include <bsd.port.mk>
