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

MAINTAINER=	perky@fallin.lv

LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||}

do-build:
	${SETUP_CMD} build_ext --libs="-ldb3" --berkeley-db=${LOCALBASE} \
	  --inplace

do-install:
	${SETUP_CMD} install -c -O1 --prefix=${PREFIX}

.include <bsd.port.mk>
