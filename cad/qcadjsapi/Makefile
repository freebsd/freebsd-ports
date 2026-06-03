PORTNAME=	qcadjsapi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.32.9.0
CATEGORIES=	cad

MAINTAINER=	mr@FreeBSD.org
COMMENT=	QJSEngine bindings for QCAD
WWW=		https://www.ribbonsoft.com/qcad.html

LICENSE=	MIT

BUILD_DEPENDS=	${NONEXISTENT}:cad/qcad:build	\
		${NONEXISTENT}:cad/qtjsapi:build
LIB_DEPENDS=	libOpenNURBS.so:graphics/opennurbs	\
		libqtjsapi.so:cad/qtjsapi	\
		libcups.so:print/cups
RUN_DEPENDS=	qcad>0:cad/qcad

USES=		compiler:c++17-lang cmake gl localbase:ldflags qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	qcad

CFLAGS+=	-DON_SIZEOF_WCHAR_T=4 -fPIC

USE_QT=		5compat base declarative svg tools
USE_GL=		opengl

PLIST_FILES=	share/qcad/plugins/libqcadjsapi.so

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64" && ${ARCH} != "powerpc" && ${ARCH} != powerpc64
CFLAGS+=	-DON_LITTLE_ENDIAN
.else
CFLAGS+=	-DON_BIG_ENDIAN
.endif

post-extract:
	${LN} -sf `${MAKE} -C ${.CURDIR}/../../cad/qcad/ -V WRKSRC` ${WRKDIR}/qcad
	${LN} -sf `${MAKE} -C ${.CURDIR}/../../cad/qtjsapi/ -V WRKSRC` ${WRKDIR}/qtjsapi

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/qcad/plugins
	${INSTALL_LIB} ${WRKDIR}/qcad/plugins/libqcadjsapi.so	\
		${STAGEDIR}${PREFIX}/share/qcad/plugins

.include <bsd.port.post.mk>
