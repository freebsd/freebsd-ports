PORTNAME=	xstatic-autosize
DISTVERSION=	1.17.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-autosize-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	autosize 1.17.2 (XStatic packaging standard)
WWW=		https://www.jacklmoore.com/autosize/

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|xs.PACKAGE_NAME|'xstatic-autosize'|g" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
