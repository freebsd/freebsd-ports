# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	4.1.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	danny@ricin.com
COMMENT=	Python to C and C++ bindings generator

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_PYTHON=	2.3
USE_QT_VER=	3

.include <bsd.port.pre.mk>

do-configure:
	@(cd ${WRKSRC} && ${SETENV} QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		${PYTHON_CMD} configure.py -b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} -v ${PREFIX}/share/sip)

post-install:
	@${PYTHON_CMD} -O -c "import sipconfig"

.include <bsd.port.post.mk>
