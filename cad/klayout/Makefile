# $FreeBSD$

PORTNAME=	klayout
PORTVERSION=	0.25.8
DISTVERSIONPREFIX=	v
CATEGORIES=	cad

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Qt-based GDS2 Viewer

LICENSE=	GPLv2

USES=		compiler:c++0x gmake gl python qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	KLayout
USE_GL=		gl
USE_RUBY=	yes
USE_QT=		core buildtools designer gui multimedia network printsupport \
		qmake sql svg testlib widgets xml xmlpatterns
USE_LDCONFIG=	yes

CXXFLAGS+=	-fPIC -I${LOCALBASE}/include/qt5
LDFLAGS+=	${LIBS} -L${LOCALBASE}/lib/qt5 -lpthread
QT5MODULES=	Core Designer Gui Multimedia MultimediaWidgets \
		Network PrintSupport Sql Svg Test Widgets Xml XmlPatterns
.for M in ${QT5MODULES}
CXXFLAGS+=	-I${LOCALBASE}/include/qt5/Qt${M}
LIBS+=		-lQt5${M}
.endfor
MAKE_ENV=	INSTALL_ROOT=${STAGEDIR}
BUILD_WRKSRC=	${WRKSRC}/build-release
INSTALL_WRKSRC=	${WRKSRC}/build-release

BROKEN_sparc64=	Does not compile on sparc64: gcc bug

do-configure:
	cd ${WRKSRC} && \
	    ${SETENV} ${MAKE_ENV} ${SH} build.sh \
		-with-qtbinding \
		-qt5 \
		-rpath ${LOCALBASE}/lib \
		-prefix ${PREFIX} \
		-python ${PYTHON_CMD} \
		-ruby ${RUBY} \
		-dry-run

post-install:
	cd ${STAGEDIR}${PREFIX} && \
	    ${MV} libklayout* ${STAGEDIR}${PREFIX}/lib && \
	    ${MV} klayout strm* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
