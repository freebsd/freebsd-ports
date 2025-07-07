PORTNAME=	xstatic-pygments
DISTVERSION=	2.9.0.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Pygments-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pygments 2.9.0 (XStatic packaging standard)
WWW=		https://pygments.org/

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|xs.PACKAGE_NAME|'xstatic-pygments'|g" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
