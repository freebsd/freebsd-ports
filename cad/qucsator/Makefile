PORTNAME=	qucsator
DISTVERSION=	0.0.20-4
DISTVERSIONSUFFIX=	-g22126bb9
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Circuit simulator of the Qucs project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	admsXml:cad/adms \
		gperf:devel/gperf

USES=		bison cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	Qucs

CXXFLAGS+=	-fPIC # workaround for https://github.com/Qucs/qucsator/issues/35

.include <bsd.port.mk>
