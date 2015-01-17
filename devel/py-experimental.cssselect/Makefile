# $FreeBSD$

PORTNAME=	experimental.cssselect
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Experimental version of lxml.cssselect

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml

USES=		python zip
USE_PYTHON=	autoplist distutils

post-patch:
	# fix pkg-plist problem with python3. This file is not installing.
	@${REINPLACE_CMD} -e 's|src/experimental/__init__.py||' \
		${WRKSRC}/src/experimental.cssselect.egg-info/SOURCES.txt
	@${RM} ${WRKSRC}/src/experimental/__init__.py \
		${WRKSRC}/src/experimental.cssselect.egg-info/SOURCES.txt.bak

.include <bsd.port.mk>
