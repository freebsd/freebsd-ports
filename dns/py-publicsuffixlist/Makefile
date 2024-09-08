PORTNAME=	publicsuffixlist
PORTVERSION=	1.0.2.20240814
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Publicsuffixlist implementation
WWW=		https://github.com/ko-zu/psl

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
#PATCH_DEPENDS=	public_suffix_list>=0:dns/public_suffix_list

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

#post-patch:
#	@${CP} ${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat ${WRKSRC}/publicsuffixlist/public_suffix_list.dat
#	@${CP} ${LOCALBASE}/share/public_suffix_list/test_psl.txt ${WRKSRC}/publicsuffixlist/test_psl.txt

.include <bsd.port.mk>
