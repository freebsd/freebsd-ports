PORTNAME=	eql5
PORTVERSION=	g20211105
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embedded Qt Lisp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE-1.MIT

LIB_DEPENDS=	libecl.so:lang/ecl

USES=		gl qmake qt:5
USE_QT=		core declarative gui help location multimedia network \
		printsupport sql svg webchannel webengine widgets \
		buildtools_build uitools_build
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	eql
GL_PROJECT=	${PORTNAME:tu}
GL_COMMIT=	82c209a46962f8a7e9f7d8f81b25cc21e8861e42

WRKSRC_SUBDIR=	src

QMAKE_CONFIGURE_ARGS=	eql5.pro

post-extract: # see https://gitlab.com/eql/EQL5/-/issues/26
	@${FIND} ${WRKSRC} -name "*.pro" | ${XARGS} ${REINPLACE_CMD} -e 's|^linux|freebsd|'

do-configure: # same as in qmake.mk but w/out -- due to the qmake bug https://bugreports.qt.io/browse/QTBUG-100811
	@cd ${_QMAKE_WRKSRC} && \
		${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} \
			${QMAKE_SOURCE_PATH} \
			${QMAKE_CONFIGURE_ARGS}

pre-build:
	@cd ${WRKSRC} && ecl -shell make.lisp

.include <bsd.port.mk>
