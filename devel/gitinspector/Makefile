# $FreeBSD$

PORTNAME=	gitinspector
PORTVERSION=	0.4.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel python

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Statistical analysis tool for git repositories

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	git:devel/git

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils concurrent optsuffix
USES=		python

GH_ACCOUNT=	ejwa
USE_GITHUB=	yes

.include <bsd.port.mk>
