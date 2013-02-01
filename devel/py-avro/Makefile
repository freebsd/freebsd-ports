# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.7.3
CATEGORIES=	devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	${PORTNAME}/stable
PKGNAMEPREFIX=	py-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Data serialization system for python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/simplejson/__init__.py:${PORTSDIR}/devel/py-simplejson
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/simplejson/__init__.py:${PORTSDIR}/devel/py-simplejson

USE_PYDISTUTILS=	easy_install
USE_PYTHON=		yes

WRKSRC=		${WRKDIR}/${DISTNAME}/lang/py

.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} 's|@AVRO_VERSION@|${PORTVERSION}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.post.mk>
