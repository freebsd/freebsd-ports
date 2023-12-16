PORTNAME=	pyBigWig
DISTVERSION=	0.3.22
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python access to bigWig files using libBigWig
WWW=		https://pypi.org/project/pyBigWig/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		localbase python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyBigWig*.so

.include <bsd.port.mk>
