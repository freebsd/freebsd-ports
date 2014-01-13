# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	instant
PORTVERSION=	${MMVERSION}.0
CATEGORIES=	devel python
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${MMVERSION}.x/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Python module for instant inlining of C and C++ code in Python

LICENSE=	LGPL3

RUN_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	instant

MAN1=		instant-clean.1 \
		instant-showcache.1
MANCOMPRESSED=	yes

MMVERSION=	1.2

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
	's|\[(join("share", "man", "man1"),|\[(join("man", "man1"),|' \
	${WRKSRC}/setup.py

.include <bsd.port.mk>
