PORTNAME=	qview
DISTVERSION=	7.1
CATEGORIES=	graphics

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Practical and minimal image viewer
WWW=		https://interversehq.com/qview/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++14-lang desktop-file-utils gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	jurplel
GH_PROJECT=	qView
USE_GL=		opengl
USE_QT=		base tools:build imageformats:run

OPTIONS_DEFINE=		KF6
OPTIONS_DEFAULT=	KF6

KF6_DESC=	HEIF and AVIF support (via kimageformats)
KF6_USES=	kde:6
KF6_USE=	KDE=kimageformats:run

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
