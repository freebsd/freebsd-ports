PORTNAME=	qtfeedback
DISTVERSION=	5.0.0-beta1-32
PORTREVISION=	1
DISTVERSIONSUFFIX=	-ga14bd0b
CATEGORIES=	deskutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Tactile Feedback Add-on Module
WWW=		https://github.com/qt/qtfeedback

DEPRECATED=	Development discontinued, does not support Qt 6
EXPIRATION_DATE=	2026-12-31

USES=		gl perl5 qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	qtproject
USE_GL=		gl
USE_PERL5=	build
USE_QT=		core declarative gui multimedia network \
		buildtools:build qmake:build testlib:build

pre-configure:
	cd ${CONFIGURE_WRKSRC} && ${QT_BINDIR}/syncqt.pl -version ${QT5_VERSION} -module QtFeedback

.include <bsd.port.mk>
