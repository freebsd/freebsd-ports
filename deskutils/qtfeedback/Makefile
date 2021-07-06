PORTNAME=	qtfeedback
DISTVERSION=	5.0.0-beta1-32
DISTVERSIONSUFFIX=	-ga14bd0b
CATEGORIES=	deskutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Tactile Feedback Add-on Module

USES=		gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	qtproject
USE_GL=		gl
USE_QT=		core declarative gui multimedia network \
		buildtools_build qmake_build

pre-configure:
	cd ${CONFIGURE_WRKSRC} && ${QT_BINDIR}/syncqt.pl -version ${QT5_VERSION} -module QtFeedback

.include <bsd.port.mk>
