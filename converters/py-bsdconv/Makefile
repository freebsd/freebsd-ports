# New ports collection makefile for:	py-bsdconv
# Date created:				11 Oct 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	6.6
CATEGORIES=	converters python
MASTER_SITES=	https://github.com/buganini/python-${PORTNAME}/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	Python wrapper for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	bsdconv.6:${PORTSDIR}/converters/bsdconv

GITVERSION=	b2eb189
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-python-${PORTNAME}-${GITVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
