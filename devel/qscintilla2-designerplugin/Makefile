# New ports collection makefile for:	qscintilla2-designerplugin
# Date created:				2007-02-09
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	designerplugin
PORTVERSION=	${QSCI2_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITES_QSCI2}
PKGNAMEPREFIX=	qscintilla2-
DISTNAME=	${QSCI2_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Designer plugin for QScintilla2 (Qt4)

LIB_DEPENDS=	qscintilla2.5:${PORTSDIR}/devel/qscintilla2

DISTINFO_FILE=	${QSCI2_DISTINFO_FILE}
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build gui xml designer
HAS_CONFIGURE=	yes

QMAKE_ARGS=	-unix PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}/designer-Qt4

.include "../py-sip/files/bsd.pyqt.mk"
.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} -e \
		's|$$$$\[QT_INSTALL_PLUGINS\]|${PREFIX}/${QT_PLUGINDIR_REL}|' \
		${WRKSRC}/designer.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS} designer.pro

post-configure:
	${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		s|^CXX .*|CXX=${CXX}|; \
		s|^LINK .*|LINK=${CXX}|' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
