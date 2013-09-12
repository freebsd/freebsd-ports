# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	shout
PORTVERSION=	0.2.1
CATEGORIES=	audio python
MASTER_SITES=	http://downloads.us.xiph.org/releases/libshout/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings for libshout2

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

USES=			pkgconfig
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}-python

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/example.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
