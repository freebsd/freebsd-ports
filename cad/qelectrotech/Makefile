PORTNAME=	qelectrotech
DISTVERSION=	0.9.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	https://git.tuxfamily.org/qet/qet.git/snapshot/
DISTNAME=	qet-${DISTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Application to design electric diagrams
WWW=		https://qelectrotech.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		desktop-file-utils gl kde:5 pkgconfig qt:5 qmake shared-mime-info \
		sqlite
USE_GL=		gl
USE_QT=		concurrent core gui network printsupport qmake sql sql-sqlite3 \
		svg widgets xml \
		buildtools:build
USE_KDE=	coreaddons widgetsaddons

OPTIONS_DEFINE=	DEBUG

DEBUG_VARS=	BUILD_TYPE=debug
DEBUG_VARS_OFF=	BUILD_TYPE=release

ALL_TARGET=	${BUILD_TYPE}-all

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
