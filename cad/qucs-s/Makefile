PORTNAME=	qucs-s
DISTVERSION=	24.1.0
CATEGORIES=	cad
MASTER_SITES=	https://github.com/ra3xdh/qucs_s/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quite Universal Circuit Simulator: GUI for circuit simulation kernels
WWW=		https://ra3xdh.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison cmake gl localbase qt:6
USE_QT=		base svg tools:build
USE_GL=		gl opengl

OPTIONS_GROUP=		BACKENDS RTDEPENDS
OPTIONS_GROUP_BACKENDS=	NGSPICE XYCE QUCSATOR
OPTIONS_GROUP_RTDEPENDS=	OCTAVE ADMS
OPTIONS_DEFAULT=	NGSPICE

BACKENDS_DESC=		Simulation backends
RTDEPENDS_DESC=		Optional run-time dependencies

NGSPICE_DESC=		ngspice mixed-signal circuit simulator
NGSPICE_RUN_DEPENDS=	ngspice:cad/ngspice_rework

XYCE_DESC=		Xyce electronic simulator
XYCE_RUN_DEPENDS=	Xyce:cad/xyce \
			mpich>0:net/mpich # mpich for the mpirun executable

QUCSATOR_DESC=		Circuit simulator of the Qucs project
QUCSATOR_RUN_DEPENDS=	qucsator:cad/qucsator

OCTAVE_DESC=		Octave is used for some non-essential features
OCTAVE_RUN_DEPENDS=	octave:math/octave

ADMS_DESC=		ADMS model generator used for some non-essential features
ADMS_RUN_DEPENDS=	admsXml:cad/adms

post-patch:
	# first the patch under files/ introduces %%PREFIX%%, and now we fix it here
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/qucs/main.cpp

.include <bsd.port.mk>
