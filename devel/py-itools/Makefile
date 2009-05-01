# New ports collection makefile for:	py-itools
# Date created:		08 Feb,2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	itools
PORTVERSION=	0.50.6
CATEGORIES=	devel python
MASTER_SITES=	http://download.hforge.org/itools/0.50/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Python library Provides Wide Range Of Capabilities

LIB_DEPENDS=	glib:${PORTSDIR}/devel/glib20

OPTIONS=	PIL   "Add support for PIL" Off \
		REPORTLAB2   "Add support for RML" Off \
		DOCUTILS   "Add support for Docutils" On

MAKE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>
.if defined(WITH_PIL)
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging
.endif

.if defined(WITH_REPORTLAB2)
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab2>2.2:${PORTSDIR}/print/py-reportlab2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab2>2.2:${PORTSDIR}/print/py-reportlab2
.endif

.if defined(WITH_DOCUTILS)
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}docutils>=0.5:${PORTSDIR}/textproc/py-docutils
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}docutils>=0.5:${PORTSDIR}/textproc/py-docutils
.endif

.include <bsd.port.post.mk>
