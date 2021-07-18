# Created by: Xin Li <delphij@FreeBSD.org>

PORTNAME=	ujson
PORTVERSION=	4.0.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Ultra fast JSON encoder and decoder for Python

LICENSE=	BSD3CLAUSE TclTk
LICENSE_COMB=	multi
LICENSE_NAME_TclTk=	Tcl/Tk License
LICENSE_TEXT_TclTk=	http://www.tcl.tk/software/tcltk/license.html
LICENSE_PERMS_TclTk=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
