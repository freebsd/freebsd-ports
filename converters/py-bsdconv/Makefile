# New ports collection makefile for:	py-bsdconv
# Date created:				11 Oct 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

CATEGORIES+=	python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	buganini@gmail.com
COMMENT=	Python wrapper for bsdconv

LIB_DEPENDS=	bsdconv.4:${PORTSDIR}/converters/bsdconv

MASTERDIR=	${.CURDIR}/../bsdconv
WRKSRC=		${WRKDIR}/${DISTNAME}/wrapper/python
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

.include "${MASTERDIR}/Makefile"
