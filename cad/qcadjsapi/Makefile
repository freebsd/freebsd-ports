PORTNAME=	qcadjsapi
DISTVERSIONPREFIX=	v
DISTVERSION=	27.0.6.0
#PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	mr@FreeBSD.org
COMMENT=	QJSEngine bindings for QCAD
WWW=		https://www.ribbonsoft.com/qcad.html

LICENSE=	MIT

#BUILD_DEPENDS=	${NONEXISTENT}:cad/qcad:build	\
#		${NONEXISTENT}:cad/qtjsapi:build
LIB_DEPENDS=	libOpenNURBS.so:graphics/opennurbs	\
		libqcadcore.so:cad/qcad	\
		libqtjsapi.so:cad/qtjsapi	\
		libcups.so:print/cups

USES=		compiler:c++17-lang cmake gl localbase:ldflags qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	qcad
GH_PROJECT=	qcadjsapi:qcadjsapi qcad:qcad qtjsapi:qtjsapi
GH_SUBDIR=	qcad:qcad qtjsapi:qtjsapi

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
	${LN} -sf ${WRKSRC}/qcad ${WRKDIR}/qcad
	${LN} -sf ${WRKSRC}/qtjsapi ${WRKDIR}/qtjsapi

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/qcad/plugins
	${INSTALL_LIB} ${WRKDIR}/qcad/plugins/libqcadjsapi.so	\
		${STAGEDIR}${PREFIX}/share/qcad/plugins

.include <bsd.port.post.mk>
