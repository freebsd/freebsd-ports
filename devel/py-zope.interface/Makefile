# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	zope.interface
PORTVERSION=	4.1.2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Interfaces for Python

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	# fix pkg-plist problem with python3. This file is not installing.
	@${REINPLACE_CMD} -e 's|src/zope/__init__.py||' \
		${WRKSRC}/src/zope.interface.egg-info/SOURCES.txt
	@${RM} ${WRKSRC}/src/zope/__init__.py \
		${WRKSRC}/src/zope.interface.egg-info/SOURCES.txt.bak
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/zope/interface/_zope_interface_coptimizations.so

.include <bsd.port.mk>
