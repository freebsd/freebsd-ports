# New ports collection makefile for:	py-tarfile
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	tarfile
PORTVERSION=	0.3
CATEGORIES=	archivers python
MASTER_SITES=	http://www.gustaebel.de/lars/tarfile/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 200
IGNORE=		needs Python 2.0 at least
.else
.if ${PYTHON_REL} < 220
PLIST_SUB+=	UNDERPY22=""
.else
PLIST_SUB+=	UNDERPY22="@comment "
.endif
.endif

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install -c -O1 --prefix=${PREFIX}

.include <bsd.port.post.mk>
