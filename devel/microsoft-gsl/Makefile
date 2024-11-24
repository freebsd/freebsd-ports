PORTNAME=	microsoft-gsl
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.0
PORTREVISION=	2
CATEGORIES=	devel

PATCH_SITES=	https://github.com/microsoft/GSL/commit/
PATCHFILES=	87f9d768866548b5b86e72be66c60c5abd4d9b37.patch:-p1

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Guidelines Support Library
WWW=		https://github.com/microsoft/GSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	GSL

CMAKE_OFF=	GSL_TEST

NO_ARCH=	yes

.include <bsd.port.mk>
