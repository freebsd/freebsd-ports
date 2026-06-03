PORTNAME=	qelectrotech
DISTVERSION=	0.100
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}-source-mirror/releases/download/${DISTVERSION}/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Application to design electric diagrams
WWW=		https://qelectrotech.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		desktop-file-utils gl kde:5 pkgconfig qmake qt:5 \
		shared-mime-info sqlite
USE_GL=		gl
USE_KDE=	coreaddons widgetsaddons
USE_QT=		concurrent core gui network printsupport qmake sql sql-sqlite3 \
		svg widgets xml buildtools:build

ALL_TARGET=	${BUILD_TYPE}-all

OPTIONS_DEFINE=	DEBUG

DEBUG_VARS=	BUILD_TYPE=debug
DEBUG_VARS_OFF=	BUILD_TYPE=release

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,doc/,share/doc/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e '/QET_MAN_PATH/s,man/,share/man/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,../share,share,g' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
