PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Binary data editor for reverse engineering
WWW=		https://github.com/spuriousdata/BinGrok

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qmake qt:5
USE_QT=		buildtools:build core gui widgets
USE_GITHUB=	yes
GH_ACCOUNT=	spuriousdata
GH_PROJECT=	BinGrok

QMAKE_SOURCE_PATH=	${WRKSRC}/src

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${GH_PROJECT} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
