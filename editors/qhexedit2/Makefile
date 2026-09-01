PORTNAME=	qhexedit2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	editors devel

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Hex editor widget for Qt framework
WWW=		https://simsys.github.io/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	Simsys
USE_GL=		opengl
USE_QT=		base tools:build

QMAKE_SOURCE_PATH=	src/qhexedit.pro

post-build:
	cd ${WRKSRC}/example && ${QMAKE} qhexedit.pro && ${MAKE_CMD}

post-install:
	@${MKDIR} ${STAGEDIR}${QT_INCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${QT_INCDIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/example/qhexedit ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
