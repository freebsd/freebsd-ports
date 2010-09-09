# New ports collection makefile for:	py-bsdconv
# Date created:				11 Oct 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	3.6.2
CATEGORIES=	converters python
MASTER_SITES=	http://security-hole.info/distfile/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	buganini-bsdconv-3.6.2-0-g66aab4b

MAINTAINER=	buganini@gmail.com
COMMENT=	Python wrapper for bsdconv

LIB_DEPENDS=	bsdconv.3:${PORTSDIR}/converters/bsdconv

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}

WRKSRC=		${WRKDIR}/buganini-bsdconv-66aab4b/wrapper/python

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
