# New ports collection makefile for:	ja-pycodec
# Date created:		29 April 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pycodec
PORTVERSION=	1.3
CATEGORIES=	japanese python converters
MASTER_SITES=	http://pseudo.grad.sccs.chukyo-u.ac.jp/~kajiyama/python/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
DISTNAME=	JapaneseCodecs-${PORTVERSION}

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}
PYDIST_SETUP=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-build:
	${PYDIST_SETUP} build

do-install:
	${PYDIST_SETUP} install

.include <bsd.port.mk>
