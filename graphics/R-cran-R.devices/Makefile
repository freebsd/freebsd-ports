PORTNAME=	R.devices
DISTVERSION=	2.17.3
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Unified Handling of Graphics Devices
WWW=		https://cran.r-project.org/package=R.devices

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	multi

RUN_DEPENDS=	R-cran-base64enc>=0.1.2:converters/R-cran-base64enc \
		R-cran-R.methodsS3>=1.8.1:devel/R-cran-R.methodsS3 \
		R-cran-R.oo>=1.24.0:devel/R-cran-R.oo \
		R-cran-R.utils>=2.10.1:devel/R-cran-R.utils
TEST_DEPENDS=	R-cran-digest>=0.6.13:security/R-cran-digest \
		R-cran-R.rsp>0:textproc/R-cran-R.rsp

USES=		cran:auto-plist

.include <bsd.port.mk>
