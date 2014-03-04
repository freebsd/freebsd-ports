# $FreeBSD$

PORTNAME=	linguisttools
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt localization tools

USE_QT5=	core qmldevtools_build xml buildtools_build
QT_DIST=	tools
USES=		qmake

WRKSRC_SUBDIR=	src/linguist

post-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS.*linguist/ d' \
		${WRKSRC}/linguist.pro

pre-configure:
# Generate qt_lib_uitools.pri to fix CMake files creation.
	@${REINPLACE_CMD} -e '/QT.*widgets/ d' \
		${WRKSRC:H}/designer/src/lib/uilib/uilib.pri
	@cd ${WRKSRC:H}/designer/src/uitools && \
		${SETENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-install:
.for f in lrelease lupdate
	${INSTALL_MAN} ${WRKSRC}/${f}/${f}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
