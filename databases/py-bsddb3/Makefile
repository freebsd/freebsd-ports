# New ports collection makefile for:	py-bsddb3
# Date created:				22 March 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	bsddb3
PORTVERSION=	3.3.0
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pybsddb
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	--libs="-ldb3" --berkeley-db=${LOCALBASE}

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||}

.include <bsd.port.mk>
