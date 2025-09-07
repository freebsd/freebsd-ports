PORTNAME=	qucs-s
DISTVERSION=	25.2.0
CATEGORIES=	cad
MASTER_SITES=	https://github.com/ra3xdh/qucs_s/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quite Universal Circuit Simulator: GUI for circuit simulation kernels
WWW=		https://ra3xdh.github.io/ \
		https://github.com/ra3xdh/qucs_s/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dos2unix:converters/dos2unix \
		gperf:devel/gperf \
		vulkan-headers>0:graphics/vulkan-headers

USES=		bison cmake gl localbase qt:6
USE_GL=		opengl
USE_QT=		base charts svg tools:build

OPTIONS_DEFAULT=		NGSPICE
OPTIONS_GROUP=			BACKENDS RTDEPENDS
OPTIONS_GROUP_BACKENDS=		NGSPICE QUCSATOR XYCE
OPTIONS_GROUP_RTDEPENDS=	ADMS OCTAVE

ADMS_DESC=	ADMS model generator used for some non-essential features
BACKENDS_DESC=	Simulation backends
NGSPICE_DESC=	ngspice mixed-signal circuit simulator
OCTAVE_DESC=	Octave is used for some non-essential features
QUCSATOR_DESC=	Circuit simulator of the Qucs project
RTDEPENDS_DESC=	Optional run-time dependencies
XYCE_DESC=	Xyce electronic simulator

ADMS_RUN_DEPENDS=	admsXml:cad/adms
NGSPICE_RUN_DEPENDS=	ngspice:cad/ngspice_rework
OCTAVE_RUN_DEPENDS=	octave:math/octave
QUCSATOR_RUN_DEPENDS=	qucsator:cad/qucsator
XYCE_RUN_DEPENDS=	mpirun:net/mpich \
			Xyce:cad/xyce

post-patch:
# first the patch under files/ introduces %%LOCALBASE%%, and now we fix it here
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/qucs/settings.cpp

.include <bsd.port.mk>
