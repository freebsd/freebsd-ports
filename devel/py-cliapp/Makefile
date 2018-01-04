# $FreeBSD$

PORTNAME=	cliapp
PORTVERSION=	1.20160724
CATEGORIES=	devel
MASTER_SITES=	http://git.liw.fi/cgi-bin/cgit/cgit.cgi/cliapp/snapshot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Python framework for command line utilities

LICENSE=	GPLv2
LICENSE_FILES=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${FLAVOR}

USES=		python:2
NO_ARCH=	yes

USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
