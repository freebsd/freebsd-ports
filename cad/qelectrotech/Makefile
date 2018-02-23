# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qelectrotech
PORTVERSION=	0.5
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://download.tuxfamily.org/qet/tags/20151127/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QElectroTech is application to design electric diagrams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib desktop-file-utils qmake shared-mime-info
USE_QT5=	buildtools_build gui network printsupport \
		sql-sqlite3 svg xml

OPTIONS_DEFINE=       DEBUG

DEBUG_VARS=           BUILD_TYPE=debug
DEBUG_VARS_OFF=       BUILD_TYPE=release

ALL_TARGET=           ${BUILD_TYPE}-all

pre-configure:
	${MV} ${WRKSRC}/man/files/pt ${WRKSRC}/man/files/pt_PT
	${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,doc/,share/doc/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,../share,share,g' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
