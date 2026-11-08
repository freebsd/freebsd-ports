PORTNAME=	qucsator
DISTVERSION=	0.0.20-4
DISTVERSIONSUFFIX=	-g22126bb9
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Circuit simulator of the Qucs project
WWW=		https://github.com/Qucs/qucsator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	admsXml:cad/adms \
		gperf:devel/gperf

USES=		bison cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	Qucs

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/Qucs/qucsator/issues/59

CXXFLAGS+=	-fPIC # workaround for https://github.com/Qucs/qucsator/issues/35

MAKE_JOBS_UNSAFE=	yes # admsXml writes shared .adms.implicit.xml, races in parallel builds
.include <bsd.port.mk>
