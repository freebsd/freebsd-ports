# $FreeBSD$

PORTNAME=	mirtk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0-42
DISTVERSIONSUFFIX=	-g7390df6
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Medical Image Registration ToolKit (MIRTK)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		nifticlib>0:science/nifticlib

USES=		cmake compiler:c++11-lang eigen:3 perl5 python
USE_GITHUB=	yes
GH_ACCOUNT=	BioMedIA
GH_PROJECT=	${PORTNAME:tu}
USE_LDCONFIG=	yes

post-stage: # https://github.com/BioMedIA/MIRTK/issues/674
	@${RM} ${STAGEDIR}${PREFIX}/bin/uninstall-mirtk
	@${REINPLACE_CMD} -i '' 's|${STAGEDIR}||' ${STAGEDIR}${PREFIX}/lib/cmake/mirtk/MIRTKInstallManifest.txt

.include <bsd.port.mk>
