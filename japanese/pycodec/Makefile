# New ports collection makefile for:	ja-pycodec
# Date created:		29 April 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pycodec
PORTVERSION=	1.4.3
CATEGORIES=	japanese python converters
MASTER_SITES=	ftp://ftp.python.jp/JapaneseCodecs/ \
		http://pseudo.grad.sccs.chukyo-u.ac.jp/~kajiyama/python/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
DISTNAME=	JapaneseCodecs-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.en ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCSDIR}

.include <bsd.port.mk>
