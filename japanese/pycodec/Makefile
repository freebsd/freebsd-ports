# New ports collection makefile for:	ja-pycodec
# Date created:		29 April 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pycodec
PORTVERSION=	1.4.5
CATEGORIES=	japanese python converters
MASTER_SITES=	http://www.python.jp/Zope/download/JapaneseCodecs/ \
		http://pseudo.grad.sccs.chukyo-u.ac.jp/~kajiyama/python/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
DISTNAME=	JapaneseCodecs-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
DOCSDIR=	${PREFIX}/share/doc/ja-pycodec
PLIST_SUB=	PYTHON_SITELIBDIR="lib/${PYTHON_VERSION}/site-packages"
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install -c -O1 --prefix=${PREFIX}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.en ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCSDIR}
.endif

.include <bsd.port.mk>
