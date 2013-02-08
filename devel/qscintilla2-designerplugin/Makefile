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
USE_QT4=	qmake_build moc_build gui xml designer
HAS_CONFIGURE=	yes

QMAKE_ARGS=	-unix PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}/designer-Qt4

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} -e \
		's|$$$$\[QT_INSTALL_PLUGINS\]|${PREFIX}/${QT_PLUGINDIR_REL}|' \
		${WRKSRC}/designer.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS} designer.pro

.include <bsd.port.post.mk>
