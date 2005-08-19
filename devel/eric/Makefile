# New ports collection makefile for:	eric
# Date created:				20 January 2004
# Whom:					leafy <leafy@leafy.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	eric
PORTVERSION=	3.7.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	eric-ide

MAINTAINER=	leafy@leafy.idv.tw
COMMENT=	A Python IDE implemented using PyQt and QScintilla

BUILD_DEPENDS=	${X11BASE}/lib/libqscintilla.so:${PORTSDIR}/x11-toolkits/qscintilla\
		${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip\
		pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} install.py -b ${PREFIX}/bin/ \
		-d ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
