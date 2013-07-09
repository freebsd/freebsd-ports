# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	designerplugin
PORTVERSION=	${PYQT4_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtDesigner plugin

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PKGNAMEPREFIX}designer>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-designer

BUILD_WRKSRC=	${WRKSRC}/designer
INSTALL_WRKSRC=	${WRKSRC}/designer

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_QT4=	gui xml designer moc_build qmake_build

PATCHDIR=	${.CURDIR}/../py-qt4-core/files
ARGS=		-b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-p ${PREFIX}/${QT_PLUGINDIR_REL} \
		-q ${QMAKE} \
		--confirm-license \
		--enable QtDesigner \
		CC="${CC}" CXX="${CXX}" LINK="${CXX}" LINK_SHLIB="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"

.include "${.CURDIR}/../py-qt4/bsd.pyqt.mk"

.if defined(WITH_DEBUG)
ARGS+=		--debug --trace
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

.include <bsd.port.mk>
