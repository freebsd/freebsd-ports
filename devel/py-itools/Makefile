# New ports collection makefile for:	py-itools
# Date created:		08 Feb,2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	itools
PORTVERSION=	0.60.3
CATEGORIES=	devel python
MASTER_SITES=	http://download.hforge.org/itools/0.60/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Python library Provides Wide Range Of Capabilities

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab2>=2.3:${PORTSDIR}/print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}gobject>=2.16.1:${PORTSDIR}/devel/py-gobject
RUN_DEPENDS+=	${BUILD_DEPENDS}
LIB_DEPENDS=	glib:${PORTSDIR}/devel/glib20

MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
