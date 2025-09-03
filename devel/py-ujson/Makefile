PORTNAME=	ujson
PORTVERSION=	5.11.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Ultra fast JSON encoder and decoder for Python
WWW=		https://github.com/esnme/ultrajson

LICENSE=	BSD3CLAUSE TclTk
LICENSE_COMB=	multi
LICENSE_NAME_TclTk=	Tcl/Tk License
LICENSE_TEXT_TclTk=	http://www.tcl.tk/software/tcltk/license.html
LICENSE_PERMS_TclTk=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

.include <bsd.port.mk>
