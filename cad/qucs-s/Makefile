PORTNAME=	qucs-s
DISTVERSION=	0.0.24
PORTREVISION=	4
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quite Universal Circuit Simulator: GUI for circuit simulation kernels

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake qt:5
USE_QT=		core gui printsupport svg widgets buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	ra3xdh
GH_PROJECT=	qucs_s

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
