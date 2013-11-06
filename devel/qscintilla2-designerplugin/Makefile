# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	designerplugin
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	qscintilla2-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 Designer plugin for QScintilla2

LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2

DISTINFO_FILE=	${QSCI2_DISTINFO_FILE}
USES=		qmake
USE_QT4=	qmake_build moc_build gui xml designer
HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/designer-Qt4Qt5

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"

pre-configure:
	${REINPLACE_CMD} -e \
		's|$$$$\[QT_INSTALL_PLUGINS\]|${PREFIX}/${QT_PLUGINDIR_REL}|' \
		${WRKSRC}/designer.pro

.include <bsd.port.mk>
