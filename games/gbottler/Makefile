# New ports collection makefile for:	gbottler
# Date created:				3 Apr 2004
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME=	gbottler
PORTVERSION=	0.1.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	gbottler/45155

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	SSTP Bottle client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/_xmlplus/sax/saxutils.py:${PORTSDIR}/textproc/py-xml

PYVERSION=	${PYTHON_VERSION:S/^python//}
.if defined(PYTHON_VERSION) && ${PYVERSION:S/.//} < 24
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec
.endif # defined(PYVERSION) && ${PYVERSION:S/.//} < 24

PLIST_SUB=	VERSION=${PORTVERSION}

USE_PYTHON=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
