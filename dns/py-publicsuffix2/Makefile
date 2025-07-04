PORTNAME=	publicsuffix2
PORTVERSION=	2.20191221
PORTREVISION=	65
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ml@netfence.it
COMMENT=	Get public suffix of domain name from Public Suffix List (Fork)
WWW=		https://github.com/nexb/python-publicsuffix2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/publicsuffix2.LICENSE

PATCH_DEPENDS=	public_suffix_list>=0:dns/public_suffix_list

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat ${WRKSRC}/src/publicsuffix2/public_suffix_list.dat

.include <bsd.port.mk>
