# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dateutil
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-dateutil-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Provides powerful extensions to the standard datetime module

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

# Fix incorrect permissions
post-patch:
	@${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} ";"
	@${REINPLACE_CMD} -e 's|import winreg|from six.moves import winreg|' ${WRKSRC}/dateutil/tzwin.py

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} test.py

.include <bsd.port.mk>
