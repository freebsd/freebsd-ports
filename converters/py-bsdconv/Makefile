# New ports collection makefile for:	py-bsdconv
# Date created:				11 Oct 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	4.3
CATEGORIES=	converters python
MASTER_SITES=	http://cloud.github.com/downloads/buganini/bsdconv/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	buganini@gmail.com
COMMENT=	Python wrapper for bsdconv

LIB_DEPENDS=	bsdconv.4:${PORTSDIR}/converters/bsdconv

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/wrapper/python

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
