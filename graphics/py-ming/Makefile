# New ports collection makefile for:	Python/Ming
# Date created:		16 Oct 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.0.3a
CATEGORIES=	graphics python
MASTER_SITES=	http://www.opaque.net/ming/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${SWIG}:${PORTSDIR}/devel/SWIG-devel
LIB_DEPENDS=	ming.1:${PORTSDIR}/graphics/ming

USE_PYTHON=	yes

MD5_FILE=	${PORTSDIR}/graphics/ming/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/py_ext
MAKE_ARGS=	PYTHON_VERSION="${PYTHON_VERSION}" SWIG="${SWIG}"

SWIG=		swig1.3

EXAMPLES=	shape.py test.py

post-extract:
	${LN} -sf ../ming.i ${WRKSRC}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${PYTHON_VERSION}/ming
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/${PYTHON_VERSION}/ming/
.endfor
.endif

.include <bsd.port.mk>
