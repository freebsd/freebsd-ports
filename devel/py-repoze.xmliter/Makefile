# $FreeBSD$

PORTNAME=	repoze.xmliter
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Wrapper for lxml trees which serializes to string upon iteration

LICENSE=	REPOZE
LICENSE_NAME=	Repoze License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}future>0:${PORTSDIR}/devel/py-future

USES=		python zip
USE_PYTHON=	autoplist distutils

post-patch:
	# fix pkg-plist problem with python3. This file is not installing.
	@${REINPLACE_CMD} -e 's|repoze/__init__.py||' \
		${WRKSRC}/repoze.xmliter.egg-info/SOURCES.txt
	@${RM} ${WRKSRC}/repoze/__init__.py \
		${WRKSRC}/repoze.xmliter.egg-info/SOURCES.txt.bak

.include <bsd.port.mk>
