# New ports collection makefile for:	py-iconv
# Date created:		11 September 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$

PORTNAME=	iconv
PORTVERSION=	1.0
CATEGORIES=	converters python
MASTER_SITES=	ftp://people.linuxkorea.co.kr/pub/Python/ \
		http://cvsup3.kr.freebsd.org/~perky/distfiles/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	iconv:${PORTSDIR}/converters/iconv

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}

SETUPINFO=	,libraries=["iconv"],library_dirs=["${LOCALBASE}/lib"],\
		include_dirs=["${LOCALBASE}/include"]

post-patch:
	cd ${WRKSRC} && ${SED} 's!^\(.*ext_mod.*\)\()]\)$$!\1${SETUPINFO}\2!g'\
		setup.py > setup.py.tmp && ${CAT} setup.py.tmp > setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install

.include <bsd.port.mk>
