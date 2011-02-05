# New ports collection makefile for:	py-zinnia

# Date created:				15 Aug 2010
# Whom:					Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	zinnia
PORTVERSION=	0.06
CATEGORIES=	japanese python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Zinnna Python Interface

LIB_DEPENDS=	zinnia.0:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	zinnia:${PORTSDIR}/japanese/zinnia

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	${PORTNAME}_python
PYDISTUTILS_PKGVERSION=	0.0.0

.include <bsd.port.pre.mk>

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
MAKE_ENV:=	${CONFIGURE_ENV}

post-extract:
	${CP} -pR ${WRKSRC}/python/* ${WRKSRC}/

.include <bsd.port.post.mk>
