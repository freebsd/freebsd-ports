# $FreeBSD$

PORTNAME=	pybugz
DISTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bugmeister@FreeBSD.org
COMMENT=	Python command-line interface to bugzilla

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes

USES=		python:3.3+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	williamh

post-patch:
	${REINPLACE_CMD} 's,share/man,man,' ${WRKSRC}/${PYSETUP}
	${REINPLACE_CMD} -e 's,/usr,${PREFIX},' \
		-e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/man/pybugz.d.5

.include <bsd.port.mk>
