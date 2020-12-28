# $FreeBSD$

PORTNAME=	gitinspector
PORTVERSION=	0.4.4
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel python
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Statistical analysis tool for git repositories

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	git:devel/git

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python:3.6+

GH_ACCOUNT=	ejwa
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/data_files/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
