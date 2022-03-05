PORTNAME=	libsedml
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.28
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ SED-ML library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	libsbml>0:biology/libsbml \
		libnuml>0:biology/libnuml # statically linked, even into a shared library, see https://github.com/fbergmann/libSEDML/issues/155
RUN_DEPENDS=	libsbml>0:biology/libsbml \
		libnuml>0:biology/libnuml # when static lib libnuml.a is fixed these should be run-time dependency

USES=		cmake compiler:c++11-lang gnome
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fbergmann
GH_PROJECT=	libSEDML

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR}

# the project builds static libs with -fPIC, see https://github.com/fbergmann/libSEDML/issues/155

.include <bsd.port.mk>
