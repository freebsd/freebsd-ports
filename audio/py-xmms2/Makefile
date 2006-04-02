# New ports collection makefile for:	py-xmms2
# Date created:				18 Mar 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alex@foxybanana.com
COMMENT=	Python Bindings for XMMS2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Pyrex/__init__.py:${PORTSDIR}/devel/pyrex \
		${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2
RUN_DEPENDS=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USE_PYTHON=	yes

PLIST=		${.CURDIR}/pkg-plist

SCONS_TARGET=	src/clients/lib/python/xmmsclient.so
XMMS2_SLAVE=	python

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} ${SCONS_TARGET} ${PYTHONPREFIX_SITELIBDIR}/xmmsclient.so

.include "${MASTERDIR}/Makefile"
