# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	4.0.r1
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	eugos@gmx.net
COMMENT=	Python to C and C++ bindings generator

USE_PYTHON=	yes
USE_QT_VER=	3

do-configure:
	@(cd ${WRKSRC} && ${SETENV} QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		${PYTHON_CMD} configure.py -b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} -v ${PREFIX}/share/sip)

.include <bsd.port.mk>
