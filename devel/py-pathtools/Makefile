# $FreeBSD$

PORTNAME=	pathtools
PORTVERSION=	0.1.2
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	File system general utilities for Python

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

# Python3 ready (installation tested)
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PKGNAMEPREFIX}sphinx>=1.1.3:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-build:
	(cd ${WRKSRC}/docs ; ${MAKE} html)

post-install:
	(cd ${WRKSRC}/docs/build/html ; ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
