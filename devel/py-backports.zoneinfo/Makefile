PORTNAME=	backports.zoneinfo
DISTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Backport of the standard library module zoneinfo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils
# We already have Python 3.7 as minimal supported release, force positive checks
CFLAGS+=	-DATLEAST_37

.include <bsd.port.mk>
