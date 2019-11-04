# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qelectrotech
DISTVERSION=	0.7.0
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	https://git.tuxfamily.org/qet/qet.git/snapshot/
DISTNAME=	qet-${DISTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	QElectroTech is application to design electric diagrams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib desktop-file-utils gl kde:5 qmake qt:5 \
		shared-mime-info
USE_GL=		gl
USE_QT=		concurrent core gui network printsupport sql sql-sqlite3 \
		svg widgets xml \
		buildtools_build
USE_KDE=	coreaddons widgetsaddons

OPTIONS_DEFINE=       DEBUG DOCS

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

post-stage:
	# Sources come with accidental Dolphin state
	${RM} ${STAGEDIR}${DATADIR}/elements/10_electric/20_manufacturers_articles/bosch_rexroth/.directory

.include <bsd.port.mk>
