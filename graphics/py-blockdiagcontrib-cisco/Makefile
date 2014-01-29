# $FreeBSD$

PORTNAME=	blockdiagcontrib-cisco
PORTVERSION=	0.1.7
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Networking shapes for blockdiag designed by Cisco

RUN_DEPENDS=	${PKGNAMEPREFIX}blockdiag>=0.8.0:${PORTSDIR}/graphics/py-blockdiag

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
x-generate-plist:
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} -type f | ${SORT} | \
	${SED} -e 's,${PYTHON_SITELIBDIR},%%PYTHON_SITELIBDIR%%,' \
	-e 's,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,' >> pkg-plist.new
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} -type d -depth | ${SORT} -r | \
	${SED} -e 's,${PYTHON_SITELIBDIR},@dirrm %%PYTHON_SITELIBDIR%%,' \
	-e 's,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,' >> pkg-plist.new

.include <bsd.port.mk>
