# New ports collection makefile for:	qelectrotech
# Date created:		2010-03-24
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	qelectrotech
PORTVERSION=	0.22
CATEGORIES=	cad
MASTER_SITES=	http://download.tuxfamily.org/qet/tags/20100313/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	QElectroTech is application to design electric diagrams

USE_QT_VER=	4
QT_COMPONENTS=	gui network svg xml \
		moc_build qmake_build rcc_build uic_build
INSTALLS_ICONS=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAN1=		qelectrotech.1
MANLANG=	"" es fr.ISO8859-1 fr.UTF-8 fr pt_PT
MANCOMPRESSED=	yes

post-extract:
	@${CP} ${WRKSRC}/LICENSE ${WRKSRC}/COPYING

do-configure:
	${MV} ${WRKSRC}/man/files/pt ${WRKSRC}/man/files/pt_PT
	${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,doc/,share/doc/,g' \
		${WRKSRC}/${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,../share,share,g' \
		${WRKSRC}/${PORTNAME}.pro
	cd ${WRKSRC} && ${QMAKE} ${PORTNAME}.pro

.include <bsd.port.mk>
