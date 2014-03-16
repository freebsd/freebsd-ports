# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qelectrotech
PORTVERSION=	0.3
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://download.tuxfamily.org/qet/tags/20130928/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	vg@FreeBSD.org
COMMENT=	QElectroTech is application to design electric diagrams

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qmake
USE_QT4=	gui moc_build network rcc_build \
		sql-sqlite3_run svg uic_build xml designer
USE_GCC=	yes
INSTALLS_ICONS=	yes

CXXFLAGS+=	"-fno-ipa-sra"
QMAKE_ARGS+=	QMAKE_RPATHDIR="${_GCC_RUNTIME}"

MAN1=		qelectrotech.1
MANLANG=	"" cs el es fr.ISO8859-1 fr.UTF-8 fr it pl pt_PT
MANCOMPRESSED=	yes

pre-configure:
	${MV} ${WRKSRC}/man/files/pt ${WRKSRC}/man/files/pt_PT
	${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,doc/,share/doc/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,../share,share,g' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
