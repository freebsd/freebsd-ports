# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	zinnia
PORTVERSION=	0.06
CATEGORIES=	japanese python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Python interface for Zinnia

LIB_DEPENDS=	libzinnia.so:japanese/zinnia
RUN_DEPENDS=	zinnia:japanese/zinnia

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	${PORTNAME}_python
PYDISTUTILS_PKGVERSION=	0.0.0

LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV:=	${CONFIGURE_ENV}

post-extract:
	${CP} -a ${WRKSRC}/python/* ${WRKSRC}

.include <bsd.port.mk>
