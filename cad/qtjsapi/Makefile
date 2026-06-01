PORTNAME=	qtjsapi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.32.9.0
CATEGORIES=	cad devel

MAINTAINER=	mr@FreeBSD.org
COMMENT=	QJSEngine bindings for the Qt 6 API
WWW=		https://www.ribbonsoft.com/qcad.html

LICENSE=	MIT

LIB_DEPENDS=	libcups.so:print/cups

USES=		compiler:c++17-lang cmake gl qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	qcad

USE_QT=		5compat base declarative svg tools
USE_GL=		opengl
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libqtjsapi.so	\
		lib/libqtjsapi.so.0

do-install:
	${INSTALL_LIB} ${BUILD_WRKSRC}/out/libqtjsapi.so	\
		${STAGEDIR}${PREFIX}/lib/libqtjsapi.so.0
	${LN} -sf libqtjsapi.so.0 ${STAGEDIR}${PREFIX}/lib/libqtjsapi.so

.include <bsd.port.mk>
